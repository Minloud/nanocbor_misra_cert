/*
 * SPDX-License-Identifier: CC0-1.0
 */

/**
 * @defgroup    nanocbor_config NanoCBOR configuration header
 * @brief       Provides compile-time configuration for nanocbor
 *
 * @{
 *
 * @file
 *
 * @author      Koen Zandberg <koen@bergzand.net>
 */

#ifndef NANOCBOR_CONFIG_H
#define NANOCBOR_CONFIG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Recursion limit when using @ref nanocbor_skip.
 */
#ifndef NANOCBOR_RECURSION_MAX
#define NANOCBOR_RECURSION_MAX 10
#endif

/**
 * @brief library providing htonll, be64toh or equivalent. Must also provide
 * the reverse operation (ntohll, htobe64 or equivalent)
 */
#ifndef NANOCBOR_BYTEORDER_HEADER
#define NANOCBOR_BYTEORDER_HEADER <machine/endian.h>
#endif

/**
 * @brief call providing htonll or be64toh or equivalent functionality
 *
 * must take a uint64_t big endian and return it in host endianess
 */
#ifndef NANOCBOR_BE64TOH_FUNC
#define NANOCBOR_BE64TOH_FUNC(be) (be64toh(be))
#endif

/**
 * @brief call providing htonll or htobe64 or equivalent functionality
 *
 * must take a uint64_t in host endianess and return the big endian value
 */
#ifndef NANOCBOR_HTOBE64_FUNC
#define NANOCBOR_HTOBE64_FUNC(he) htobe64(he)
#endif

/**
 * @brief call providing htonl or htobe32 or equivalent functionality
 *
 * must take a uint32_t in host endianess and return the big endian value
 */
#ifndef NANOCBOR_HTOBE32_FUNC
#define NANOCBOR_HTOBE32_FUNC(he) htobe32(he)
#endif

/**
 * @brief configuration for size_t SIZE_MAX equivalent
 */
#ifndef NANOCBOR_SIZE_SIZET
#if (SIZE_MAX == UINT16_MAX)
#define NANOCBOR_SIZE_SIZET NANOCBOR_SIZE_SHORT
#elif (SIZE_MAX == UINT32_MAX)
#define NANOCBOR_SIZE_SIZET NANOCBOR_SIZE_WORD
#elif (SIZE_MAX == UINT64_MAX)
#define NANOCBOR_SIZE_SIZET NANOCBOR_SIZE_LONG
#else
#error ERROR: unable to determine maximum size of size_t
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* NANOCBOR_CONFIG_H */
/** @} */
