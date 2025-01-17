/*
 * $Id: phymod_system.h,v 1.1.2.4 2013/07/11 08:38:24 dayad Exp $
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright: (c) 2020 Broadcom Inc.
 * All Rights Reserved$
 */

#ifndef __PHYMOD_SYSTEM_H__
#define __PHYMOD_SYSTEM_H__

#include <phymod/phymod_types.h>

/*
 * This file defines the system interface for a given platform.
 */

#if PHYMOD_CONFIG_INCLUDE_ERROR_PRINT
#ifndef PHYMOD_DEBUG_ERROR
#error PHYMOD_DEBUG_ERROR must be defined when PHYMOD_CONFIG_INCLUDE_ERROR_PRINT is enabled
#endif
#else
#ifdef PHYMOD_DEBUG_ERROR
#undef PHYMOD_DEBUG_ERROR
#endif
#define PHYMOD_DEBUG_ERROR()
#endif

#if PHYMOD_CONFIG_INCLUDE_DEBUG_PRINT
#ifndef PHYMOD_DEBUG_VERBOSE
#error PHYMOD_DEBUG_VERBOSE must be defined when PHYMOD_CONFIG_INCLUDE_DEBUG_PRINT is enabled
#endif
#else
#ifdef PHYMOD_DEBUG_VERBOSE
#undef PHYMOD_DEBUG_VERBOSE
#endif
#define PHYMOD_DEBUG_VERBOSE()
#endif

#if PHYMOD_CONFIG_INCLUDE_DIAG_PRINT
#ifndef PHYMOD_DIAG_OUT
#error PHYMOD_DIAG_OUT must be defined when PHYMOD_CONFIG_INCLUDE_DIAG_PRINT is enabled
#endif
#else
#ifdef PHYMOD_DIAG_OUT
#undef PHYMOD_DIAG_OUT
#endif
#define PHYMOD_DIAG_OUT()
#endif

#ifndef PHYMOD_USLEEP
#error PHYMOD_USLEEP must be defined for the target system
#else
extern void PHYMOD_USLEEP(uint32_t usecs);
#endif

#ifndef PHYMOD_SLEEP
#error PHYMOD_SLEEP must be defined for the target system
#else
extern void PHYMOD_SLEEP(int secs);
#endif

#ifndef PHYMOD_MALLOC
#error PHYMOD_MALLOC must be defined for the target system
#else
extern void *PHYMOD_MALLOC(size_t size, char *descr);
#endif

#ifndef PHYMOD_FREE
#error PHYMOD_FREE must be defined for the target system
#else
extern void PHYMOD_FREE(void *ptr);
#endif

#ifndef PHYMOD_MEMSET
#error PHYMOD_MEMSET must be defined for the target system
#else
extern void *PHYMOD_MEMSET(void *dst_void, int val, size_t len);
#endif

#ifndef PHYMOD_MEMCPY
#error PHYMOD_MEMCPY must be defined for the target system
#else
extern void *PHYMOD_MEMCPY(void *dst, const void *src, size_t n);
#endif

#ifndef PHYMOD_STRCMP
#error PHYMOD_STRCMP must be defined for the target system
#else
extern int PHYMOD_STRCMP(const char *str1, const char *str2);
#endif

#ifndef PHYMOD_ASSERT
#define PHYMOD_ASSERT(expr_)
#endif

#endif /* __PHYMOD_SYSTEM_H__ */
