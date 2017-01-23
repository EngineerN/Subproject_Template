/**
* \file api_undefs.h
* \brief This header declares all of the 
*
* An "id" is integer and passing a negative or zero value is an error.
* Returning a negative denotes error.
*
*/


// We do not use #pragma once here because we need to be nice about cleaning up macros.
#ifdef __R3D_API_DEFS_H__
#error api_defs.h should be #included once and only once.
#endif

#define __R3D_API_DEFS_H__

/** \file api_defs.h
* \brief Contains preprocessor macros to facilitate creation of APIs.
* If including this file, it should be last so as to
* ensure another files doesn't undeclare these macros.
* You should \#include <api_undefs.h> at the end of a file that \#included this. */

// Macros defining how symbols are imported and exported.
/** \def R3D_EXPORT_SYMBOL
* \brief Place in front of symbol to claim its definition should be visible to external codes. */
/** \def R3D_IMPORT_SYMBOL
* \brief Place in front of symbol to claim its definition comes from external codes. */
#if defined (__linux__) || defined(__CYGWIN__)
#define R3D_EXPORT_SYMBOL __attribute__ ((visibility ("default")))
#define R3D_IMPORT_SYMBOL
#elif defined (_WIN64) || defined(_WIN32)
#define R3D_EXPORT_SYMBOL __declspec(dllexport)
#define R3D_IMPORT_SYMBOL __declspec(dllimport)
#else
#error Unknown platform.
#endif

/** \def R3D_SYMBOL
* \brief Place in front of symbol to export when building this code
* and import when consuming the library. */
#ifdef R3D_BUILD
#define R3D_SYMBOL R3D_EXPORT_SYMBOL
#else
#define R3D_SYMBOL R3D_IMPORT_SYMBOL
#endif

#ifdef R3D_BUILD
#define R3D_ENUM enum class
#else
#define R3D_ENUM enum
#endif

/** \def R3D_ENUM
* \brief Basic enum if included externally, strong enum (enum class) otherwise. */

// Ensure ABI is C.
#ifdef __cplusplus
extern "C" {
#endif
