//  Copyright (c) 2025 Matt Borland
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GPUTILS_ASSERT_HPP
#define BOOST_GPUTILS_ASSERT_HPP

#include <boost/gputils/config.hpp>

#ifdef BOOST_GPUTILS_ENABLE_CUDA

// Runtime assertions are unsupported

#define BOOST_GPUTILS_ASSERT(expr)
#define BOOST_GPUTILS_ASSERT_MSG(expr, msg)
#define BOOST_GPUTILS_STATIC_ASSERT(expr) static_assert(expr, #expr " failed")
#define BOOST_GPUTILS_STATIC_ASSERT_MSG(expr, msg) static_assert(expr, msg)

#else

#include <cassert>

#define BOOST_GPUTILS_ASSERT(expr) assert(expr)
#define BOOST_GPUTILS_ASSERT_MSG(expr, msg) assert((expr)&&(msg))
#define BOOST_GPUTILS_STATIC_ASSERT(expr) static_assert(expr, #expr " failed")
#define BOOST_GPUTILS_STATIC_ASSERT_MSG(expr, msg) static_assert(expr, msg)

#endif // BOOST_GPUTILS_ENABLE_CUDA

#endif // BOOST_GPUTILS_ASSERT_HPP
