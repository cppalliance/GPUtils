//  Copyright (c) 2024 Matt Borland
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GPUTILS_UTILITY_HPP
#define BOOST_GPUTILS_UTILITY_HPP

#include <boost/gputils/config.hpp>

#ifndef BOOST_GPUTILS_HAS_CUDA

namespace boost {
namespace gpu {

template <typename T>
BOOST_GPUTILS_GPU_ENABLED constexpr void swap(T& a, T& b)
{ 
    auto t{a}; 
    a = b; 
    b = t; 
}

template <typename T>
BOOST_GPUTILS_GPU_ENABLED constexpr T min(const T a, const T b)
{ 
    return a < b ? a : b; 
}

template <typename T>
BOOST_GPUTILS_GPU_ENABLED constexpr T max(const T a, const T b)
{ 
    return a > b ? a : b; 
}

} // namespace gpu
} // namespace boost

#else

#include <utility>

namespace boost {
namespace gpu {

using std::max;
using std::min;
using std::swap;

}
}

#endif

#endif // BOOST_GPUTILS_UTILITY_HPP
