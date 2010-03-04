/*
 * This file is part of the Shiboken Python Binding Generator project.
 *
 * Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: PySide team <contact@pyside.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation. Please
 * review the following information to ensure the GNU Lesser General
 * Public License version 2.1 requirements will be met:
 * http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 *
 * As a special exception to the GNU Lesser General Public License
 * version 2.1, the object code form of a "work that uses the Library"
 * may incorporate material from a header file that is part of the
 * Library.  You may distribute such object code under terms of your
 * choice, provided that the incorporated material (i) does not exceed
 * more than 5% of the total size of the Library; and (ii) is limited to
 * numerical parameters, data structure layouts, accessors, macros,
 * inline functions and templates.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#include <iostream>
#include "derived.h"

using namespace std;

Derived::Derived(int id) : Abstract(id)
{
}

Derived::~Derived()
{
}

Abstract*
Derived::createObject()
{
    static int id = 100;
    return new Derived(id++);
}

void
Derived::pureVirtual()
{
}

void
Derived::unpureVirtual()
{
}

bool
Derived::singleArgument(bool b)
{
    return !b;
}

double
Derived::defaultValue(int n)
{
    return ((double) n) + 0.1;
}

OverloadedFuncEnum
Derived::overloaded(int i, int d)
{
    return OverloadedFunc_ii;
}

OverloadedFuncEnum
Derived::overloaded(double n)
{
    return OverloadedFunc_d;
}

Derived::OtherOverloadedFuncEnum
Derived::otherOverloaded(int a, int b, bool c, double d)
{
    return OtherOverloadedFunc_iibd;
}

Derived::OtherOverloadedFuncEnum
Derived::otherOverloaded(int a, double b)
{
    return OtherOverloadedFunc_id;
}

struct SecrectClass : public Abstract {
    virtual void pureVirtual() {}
    virtual PrintFormat returnAnEnum() { return Short; }
};

Abstract* Derived::triggerImpossibleTypeDiscovery()
{
    return new SecrectClass;
}

struct AnotherSecretClass : public Derived {
};

Abstract* Derived::triggerAnotherImpossibleTypeDiscovery()
{
    return new AnotherSecretClass;
}
