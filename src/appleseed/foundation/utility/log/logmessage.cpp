
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2016 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// Interface header.
#include "logmessage.h"

// Standard headers.
#include <cassert>
#include <cstring>

using namespace std;

namespace foundation
{

//
// LogMessage class implementation.
//

LogMessage::Category LogMessage::get_category_value(const char* name)
{
    if (strcmp(name, "info") == 0)
        return Info;

    if (strcmp(name, "debug") == 0)
        return Debug;

    if (strcmp(name, "warning") == 0)
        return Warning;

    if (strcmp(name, "error") == 0)
        return Error;

    if (strcmp(name, "fatal") == 0)
        return Fatal;

    return NumMessageCategories;
}

const char* LogMessage::get_category_name(const Category c)
{
    static const char* Names[NumMessageCategories] =
    {
        "info",
        "debug",
        "warning",
        "error",
        "fatal"
    };

    assert(c < NumMessageCategories);

    return Names[c];
}

const char* LogMessage::get_padded_category_name(const Category c)
{
    static const char* Names[NumMessageCategories] =
    {
        "info   ",
        "debug  ",
        "warning",
        "error  ",
        "fatal  "
    };

    assert(c < NumMessageCategories);

    return Names[c];
}

}   // namespace foundation
