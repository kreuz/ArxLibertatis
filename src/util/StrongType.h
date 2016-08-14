/*
 * Copyright 2014 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Original source is copyright 2002 Robert Ramey
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef ARX_UTIL_STRONGTYPE_H
#define ARX_UTIL_STRONGTYPE_H

#include <boost/config.hpp>
#include <boost/operators.hpp>

#define ARX_STRONG_TYPEDEF(T, D)                              \
struct D                                                        \
    : boost::totally_ordered1< D                                \
    , boost::totally_ordered2< D, T                             \
    > >                                                         \
{                                                               \
    T t;                                                        \
    explicit D(const T t_) : t(t_) {}                           \
    D(): t() {}                                                 \
    D(const D & t_) : t(t_.t){}                                 \
    D & operator=(const D & rhs) { t = rhs.t; return *this;}    \
    operator const T & () const {return t; }                    \
    operator T & () { return t; }                               \
    bool operator==(const D & rhs) const { return t == rhs.t; } \
    bool operator<(const D & rhs) const { return t < rhs.t; }   \
};


template <typename TAG, typename T>
struct StrongType
	: boost::totally_ordered1<StrongType<TAG, T>
	, boost::totally_ordered2<StrongType<TAG, T>, T
	> >
{
	T t;
	explicit StrongType(const T t_) : t(t_) {}
	StrongType() : t() {}
	StrongType(const StrongType & t_) : t(t_.t) {}
	StrongType & operator=(const StrongType & rhs) { t = rhs.t; return *this;}
	bool operator==(const StrongType & rhs) const { return t == rhs.t; }
	bool operator!=(const StrongType & rhs) const { return t != rhs.t; }
	bool operator<(const StrongType & rhs) const { return t < rhs.t; }
};


#endif // ARX_UTIL_STRONGTYPE_H
