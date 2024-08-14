//  (C) Copyright John Maddock 2010.
//  (C) Copyright Matt Borland 2024.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GPUTILS_TUPLE_HPP
#define BOOST_GPUTILS_TUPLE_HPP

#include <boost/gputils/config.hpp>

#ifdef BOOST_GPUTILS_ENABLE_CUDA

#include <boost/gputils/type_traits.hpp>
#include <cuda/std/utility>

namespace boost { 
namespace gpu {

using cuda::std::pair;
using cuda::std::tuple;

using cuda::std::make_pair;

using cuda::std::get;

using cuda::std::tuple_size;
using cuda::std::tuple_element;


// The cuda/std is missing make_tuple so we need to implment it
// To properly implment it we need std::forward so we get that along the way too
namespace detail {

template <typename T>
BOOST_GPUTILS_GPU_ENABLED T&& forward(boost::gpu::remove_reference_t<T>& arg) noexcept
{
    return static_cast<T&&>(arg);
}

template <typename T>
BOOST_GPUTILS_GPU_ENABLED T&& forward(boost::gpu::remove_reference_t<T>&& arg) noexcept
{
    static_assert(!boost::gpu::is_lvalue_reference<T>::value, "Cannot forward an rvalue as an lvalue.");
    return static_cast<T&&>(arg);
}

} // namespace detail

template <typename T, typename... Ts>
BOOST_GPUTILS_GPU_ENABLED auto make_tuple(T&& t, Ts&&... ts) 
{
    return cuda::std::tuple<boost::gpu::decay_t<T>, boost::gpu::decay_t<Ts>...>(
        boost::gpu::detail::forward<T>(t), boost::gpu::detail::forward<Ts>(ts)...
    );
}

} // namespace gpu
} // namespace boost

#else

#include <tuple>

namespace boost { 
namespace gpu {

using ::std::tuple;
using ::std::pair;

// [6.1.3.2] Tuple creation functions
using ::std::ignore;
using ::std::make_tuple;
using ::std::tie;
using ::std::get;

// [6.1.3.3] Tuple helper classes
using ::std::tuple_size;
using ::std::tuple_element;

// Pair helpers
using ::std::make_pair;

} // namespace gpu
} // namespace boost

#endif // BOOST_GPUTILS_ENABLE_CUDA

#endif
