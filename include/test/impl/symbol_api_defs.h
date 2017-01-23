/*! We do not use #pragma once here because we need to be nice about cleaning up macros. */
#ifdef __SYMBOL_API_DEFS_H__
  #error api_defs.h should be #included once and only once.
#endif

#define __SYMBOL_API_DEFS_H__

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
  #if __GNUC__ >= 4
    #define _____IMPORT_SYMBOL __attribute__ ((visibility ("default")))
    #define _____EXPORT_SYMBOL __attribute__ ((visibility ("default")))
    #define _____LOCAL_SYMBOL  __attribute__ ((visibility ("hidden")))
  #else
    #define _____IMPORT_SYMBOL
    #define _____EXPORT_SYMBOL
    #define _____LOCAL_SYMBOL
  #endif

#else
  #error Unknown platform.
#endif
