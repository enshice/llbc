/**
 * @file    Macro.h
 * @author  Longwei Lai<lailongwei@126.com>
 * @date    2017-07-07
 * @version 1.0
 *
 * @brief
 */
#ifndef __LULLBC_COM_MACRO_H__
#define __LULLBC_COM_MACRO_H__

#include "lullbc/common/LibHeader.h"

// Define debug macro, same as LLBC_DEBUG
#ifdef LLBC_DEBUG
 #define LULLBC_DEBUG
#endif

// Define LULLBC_EXTERN, LULLBC_EXTERN_C macros to constraint methods/classes.
#define LULLBC_EXTERN LLBC_EXTERN
#define LULLBC_EXTERN_C LLBC_EXTERN_C

// Define Lua wrap methods constraint macro.
#define LULLBC_LUA_METH LULLBC_EXTERN_C static

#ifdef LULLBC_DEBUG
 #define lullbc_entry luaopen__lullbc_debug
#else
 #define lullbc_entry luaopen__lullbc
#endif

#endif // !__LULLBC_COM_MACRO_H__
