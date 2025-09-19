//  Copyright (c) 2025 Matt Borland
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GPUTILS_THROW_EXCEPTION_HPP
#define BOOST_GPUTILS_THROW_EXCEPTION_HPP

#include <boost/gputils/config.hpp>

#ifdef BOOST_GPUTILS_ENABLE_CUDA

// Throwing exceptions is unsupported
#define BOOST_GPUTILS_THROW_EXCEPTION(expr)

#else

#ifdef _MSC_VER
#  ifdef _CPPUNWIND
#    define BOOST_GPUTILS_THROW_EXCEPTION(expr) throw expr;
#  else
#    define BOOST_GPUTILS_THROW_EXCEPTION(expr)
#  endif
#else
#  ifdef __EXCEPTIONS
#    define BOOST_GPUTILS_THROW_EXCEPTION(expr) throw expr;
#  else
#    define BOOST_GPUTILS_THROW_EXCEPTION(expr)
#  endif
#endif

#endif // BOOST_GPUTILS_ENABLE_CUDA

#endif // BOOST_GPUTILS_THROW_EXCEPTION_HPP
