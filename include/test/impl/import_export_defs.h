/// Do not use #pragma once here, we need to be nice about cleaning up macros.
#ifdef __IMPORT_EXPORT_DEFS_H__
  #error api_defs.h should be #included once and only once.
#endif

/*! \file import_export_defs.h
 *  \brief Contains preprocessor macros to facilitate creation of APIs.
 *  If including this file, it should be last so as to
 *  ensure another files doesn't undeclare these macros.
 *  You should \#include <import_export_undefs.h> at the end of a file that 
 *  \#included this.
 */
#define __IMPORT_EXPORT_DEFS_H__

/*! \def _____EXPORT_SYMBOL
 *  \brief Place in front of symbol to claim its definition should be
 *  visible to external codes.
 */
#define _____EXPORT_SYMBOL

/*! \def _____IMPORT_SYMBOL
 *  \brief Place in front of symbol to claim its definition comes
 *  from external codes.
 */
#define _____IMPORT_SYMBOL

/*! \def _____LOCAL_SYMBOL
 *  \brief Place in front of symbol to claim its definition is
 *  for local use only.
 */
#define _____LOCAL_SYMBOL

/// Macros defining how symbols are imported and exported.
#if defined _WIN32 || defined(_WIN64) || defined __CYGWIN__ \\
    || defined(_MSC_VER) 
  #define _____IMPORT_SYMBOL __declspec(dllimport)
  #define _____EXPORT_SYMBOL __declspec(dllexport)
  #define _____LOCAL_SYMBOL
#elif defined __GNUC__
  #if __GNUC__ >= 4
    #define _____IMPORT_SYMBOL __attribute__ ((visibility ("default")))
    #define _____EXPORT_SYMBOL __attribute__ ((visibility ("default")))
    #define _____LOCAL_SYMBOL  __attribute__ ((visibility ("hidden")))
  #endif
#elif defined __clang__
  #define _____IMPORT_SYMBOL __attribute__ ((visibility ("default")))
  #define _____EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #define _____LOCAL_SYMBOL  __attribute__ ((visibility ("hidden")))
#endif

