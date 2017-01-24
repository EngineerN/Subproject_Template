/*! We do not use #pragma once here because we need to be nice about cleaning up macros. */
#ifdef __SYMBOL_API_DEFS_H__
  #error api_defs.h should be #included once and only once.
#endif

#define __SYMBOL_API_DEFS_H__

#include <impl/symbol_api_defs.h>

/*! \file api_defs.h
 *  \brief Contains preprocessor macros to facilitate creation of APIs.
 *  If including this file, it should be last so as to
 *  ensure another files doesn't undeclare these macros.
 *  You should \#include <api_undefs.h> at the end of a file that \#included this. 
 *
 *  \note This is only a template to create the api headers symbols. In order for this to work you 
 *  still need to change the naming of the symbols for it to work for your library.
 *  For convenience, all that is needed is to replace the word "TEMPLATE" with
 *  the name/abbreviation of your library.
 */


// Generic helper definitions for shared library support
#if defined _WIN32 || defined(_WIN64) || defined __CYGWIN__ || defined(_MSC_VER)
  #define _____IMPORT_SYMBOL __declspec(dllimport)
  #define _____EXPORT_SYMBOL __declspec(dllexport)
  #define _____LOCAL_SYMBOL
#elif defined __GNUC__
  #define _____IMPORT_SYMBOL __attribute__ ((visibility ("default")))
  #define _____EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #define _____LOCAL_SYMBOL  __attribute__ ((visibility ("hidden")))

#else
  #error Unknown platform.
#endif


// Now we use the generic helper definitions above to define FOX_API and FOX_LOCAL.
// FOX_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// FOX_LOCAL is used for non-api symbols.

#ifdef FOX_DLL // defined if FOX is compiled as a DLL
#ifdef FOX_DLL_EXPORTS // defined if we are building the FOX DLL (instead of using it)
#define FOX_API _____EXPORT_SYMBOL
#else
#define FOX_API _____IMPORT_SYMBOL
#endif // FOX_DLL_EXPORTS
#define FOX_LOCAL FOX_HELPER_DLL_LOCAL
#else // FOX_DLL is not defined: this means FOX is a static lib.
#define FX_API
#define FOX_LOCAL
#endif // FOX_DLL









#if defined (__linux__) || defined(__CYGWIN__)
#define TEMPLATE_EXPORT_SYMBOL __attribute__ ((visibility ("default")))conv
#define TEMPLATE_IMPORT_SYMBOL
#elif defined (_WIN64) || defined(_WIN32)
#define TEMPLATE_EXPORT_SYMBOL __declspec(dllexport)
#define TEMPLATE_IMPORT_SYMBOL __declspec(dllimport)
#else
#error Unknown platform.
#endif

/*! \def R3D_SYMBOL
 *  \brief Place in front of symbol to export when building this code
 *  and import when consuming the library. 
 */
#ifdef TEMPLATE_BUILD
#define TEMPLATE_SYMBOL R3D_EXPORT_SYMBOL
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
