/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

// #include "faust/export.h"

#include "errormsg.hh"
#include "exception.hh"

// #include "boxes.hh"
// #include "global.hh"
// #include "ppbox.hh"

#include <iostream>
using namespace std;

const char* FAUSTfilename = "????";

void faustassertaux(bool cond, const string& file, int line)
{
    if (!cond) {
        stringstream str;
        str << "ASSERT : please report this message to Faust developers (";
        str << "file: " << file.substr(file.find_last_of('/') + 1) << ", line: " << line << ", ";
        str << ")\n";
        throw faustexception(str.str());
    }
}
