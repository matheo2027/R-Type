/**
 * @file types.h
 * @brief Defines custom typedefs for various data types.
 *
 * This header file includes definitions for standard integer types
 * with specific widths and floating-point types, improving code
 * readability and portability.
 */

#pragma once

#include <cstdint>
#include <stdio.h>

/**
 * @typedef u8
 * @brief Unsigned 8-bit integer.
 */
typedef uint8_t u8;

/**
 * @typedef u16
 * @brief Unsigned 16-bit integer.
 */
typedef uint16_t u16;

/**
 * @typedef u32
 * @brief Unsigned 32-bit integer.
 */
typedef uint32_t u32;

/**
 * @typedef u64
 * @brief Unsigned 64-bit integer.
 */
typedef uint64_t u64;

/**
 * @typedef i8
 * @brief Signed 8-bit integer.
 */
typedef int8_t i8;

/**
 * @typedef i16
 * @brief Signed 16-bit integer.
 */
typedef int16_t i16;

/**
 * @typedef i32
 * @brief Signed 32-bit integer.
 */
typedef int32_t i32;

/**
 * @typedef i64
 * @brief Signed 64-bit integer.
 */
typedef int64_t i64;

/**
 * @typedef f32
 * @brief 32-bit floating-point number.
 */
typedef float f32;

/**
 * @typedef f64
 * @brief 64-bit floating-point number.
 */
typedef double f64;

/**
 * @typedef usize
 * @brief Unsigned size type, typically used for array indexing.
 */
typedef size_t usize;

/**
 * @typedef isize
 * @brief Signed size type, typically used for array indexing.
 */
typedef ssize_t isize;
