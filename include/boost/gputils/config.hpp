//  Copyright (c) 2024 Matt Borland
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GPUTILS_CONFIG_HPP
#define BOOST_GPUTILS_CONFIG_HPP

#ifdef __CUDACC__

// We have to get our include order correct otherwise you get compilation failures
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda/std/type_traits>
#include <cuda/std/utility>

#  define BOOST_GPUTILS_CUDA_ENABLED __host__ __device__
#  define BOOST_GPUTILS_HAS_GPU_SUPPORT

#  ifndef BOOST_GPUTILS_HAS_CUDA
#    define BOOST_GPUTILS_HAS_CUDA
#  endif

// We want to use force inline from CUDA instead of the host compiler
#  undef BOOST_GPUTILS_FORCEINLINE
#  define BOOST_GPUTILS_FORCEINLINE __forceinline__

#elif defined(SYCL_LANGUAGE_VERSION)

#  define BOOST_GPUTILS_SYCL_ENABLED SYCL_EXTERNAL
#  define BOOST_GPUTILS_HAS_GPU_SUPPORT

#  ifndef BOOST_GPUTILS_HAS_SYCL
#    define BOOST_GPUTILS_HAS_SYCL
#  endif

#  undef BOOST_GPUTILS_FORCEINLINE
#  define BOOST_GPUTILS_FORCEINLINE inline

#elif defined(__CUDACC_RTC__)

#  define BOOST_GPUTILS_HAS_CUDA
#  define BOOST_GPUTILS_CUDA_ENABLED __host__ __device__
#  define BOOST_GPUTILS_HAS_GPU_SUPPORT

#  ifndef BOOST_MATH_HAS_NVRTC
#    define BOOST_MATH_HAS_NVRTC
#  endif

#endif

#ifndef BOOST_GPUTILS_CUDA_ENABLED
#  define BOOST_GPUTILS_CUDA_ENABLED
#endif

#ifndef BOOST_GPUTILS_SYCL_ENABLED
#  define BOOST_GPUTILS_SYCL_ENABLED
#endif

// Not all functions that allow CUDA allow SYCL (e.g. Recursion is disallowed by SYCL)
#  define BOOST_GPUTILS_GPU_ENABLED BOOST_GPUTILS_CUDA_ENABLED BOOST_GPUTILS_SYCL_ENABLED

#if defined(__cpp_inline_variables) && __cpp_inline_variables >= 201606L
#  define BOOST_GPUTILS_INLINE_CONSTEXPR inline constexpr
#  define BOOST_GPUTILS_STATIC static
#  ifndef BOOST_GPUTILS_HAS_GPU_SUPPORT
#    define BOOST_GPUTILS_STATIC_LOCAL_VARIABLE static
#  else
#    define BOOST_GPUTILS_STATIC_LOCAL_VARIABLE
#  endif
#else
#  ifndef BOOST_GPUTILS_HAS_GPU_SUPPORT
#    define BOOST_GPUTILS_INLINE_CONSTEXPR static constexpr
#    define BOOST_GPUTILS_STATIC static
#    define BOOST_GPUTILS_STATIC_LOCAL_VARIABLE static
#  else
#    define BOOST_GPUTILS_INLINE_CONSTEXPR constexpr
#    define BOOST_GPUTILS_STATIC constexpr
#    define BOOST_GPUTILS_STATIC_LOCAL_VARIABLE
#  endif
#endif

#endif // BOOST_GPUTILS_CONFIG_HPP
