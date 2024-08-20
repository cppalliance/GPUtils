//  Copyright (c) 2024 Matt Borland
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GPUTILS_CSTDINT_HPP
#define BOOST_GPUTILS_CSTDINT_HPP

#include <boost/gputils/config.hpp>

#ifdef BOOST_GPUTILS_ENABLE_CUDA

#include <cuda/std/array>

namespace boost {
namespace gpu {

using cuda::std::array;

#else

#include <array>

namespace boost {
namespace gpu {

using std::array;

#endif

} // namespace gputils
} // namespace boost

#endif // BOOST_MATH_TOOLS_CSTDINT
