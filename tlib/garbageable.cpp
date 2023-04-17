#include "garbageable.hh"
#include <list>

static std::list<Garbageable*> gObjectTable;
static bool                    gHeapCleanup;

void* Garbageable::operator new(size_t size)
{
    // HACK : add 16 bytes to avoid unsolved memory smashing bug...
    Garbageable* res = (Garbageable*)malloc(size + 16);
    gObjectTable.push_front(res);
    return res;
}

void Garbageable::operator delete(void* ptr)
{
    // We may have cases when a pointer will be deleted during
    // a compilation, thus the pointer has to be removed from the list.
    if (!gHeapCleanup) {
        gObjectTable.remove(static_cast<Garbageable*>(ptr));
    }
    free(ptr);
}

void* Garbageable::operator new[](size_t size)
{
    // HACK : add 16 bytes to avoid unsolved memory smashing bug...
    Garbageable* res = (Garbageable*)malloc(size + 16);
    gObjectTable.push_front(res);
    return res;
}

void Garbageable::operator delete[](void* ptr)
{
    // We may have cases when a pointer will be deleted during
    // a compilation, thus the pointer has to be removed from the list.
    if (!gHeapCleanup) {
        gObjectTable.remove(static_cast<Garbageable*>(ptr));
    }
    free(ptr);
}

// Memory management
void Garbageable::cleanup()
{
    std::list<Garbageable*>::iterator it;

    // Here removing the deleted pointer from the list is pointless
    // and takes time, thus we don't do it.
    gHeapCleanup = true;
    for (it = gObjectTable.begin(); it != gObjectTable.end(); it++) {
#ifdef _WIN32
        // Hack : "this" and actual pointer are not the same: destructor cannot be called...
        Garbageable::operator delete(*it);
#else
        delete (*it);
#endif
    }

    // Reset to default state
    gObjectTable.clear();
    gHeapCleanup = false;
}
