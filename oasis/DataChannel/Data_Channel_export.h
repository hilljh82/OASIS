
// -*- C++ -*-
// $Id: Data_Channel_export.h 1857 2011-08-17 15:25:21Z hillj $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl OASIS_DATA_CHANNEL
// ------------------------------
#ifndef OASIS_DATA_CHANNEL_EXPORT_H
#define OASIS_DATA_CHANNEL_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (OASIS_DATA_CHANNEL_HAS_DLL)
#  define OASIS_DATA_CHANNEL_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && OASIS_DATA_CHANNEL_HAS_DLL */

#if !defined (OASIS_DATA_CHANNEL_HAS_DLL)
#  define OASIS_DATA_CHANNEL_HAS_DLL 1
#endif /* ! OASIS_DATA_CHANNEL_HAS_DLL */

#if defined (OASIS_DATA_CHANNEL_HAS_DLL) && (OASIS_DATA_CHANNEL_HAS_DLL == 1)
#  if defined (OASIS_DATA_CHANNEL_BUILD_DLL)
#    define OASIS_DATA_CHANNEL_Export ACE_Proper_Export_Flag
#    define OASIS_DATA_CHANNEL_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define OASIS_DATA_CHANNEL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* OASIS_DATA_CHANNEL_BUILD_DLL */
#    define OASIS_DATA_CHANNEL_Export ACE_Proper_Import_Flag
#    define OASIS_DATA_CHANNEL_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define OASIS_DATA_CHANNEL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* OASIS_DATA_CHANNEL_BUILD_DLL */
#else /* OASIS_DATA_CHANNEL_HAS_DLL == 1 */
#  define OASIS_DATA_CHANNEL_Export
#  define OASIS_DATA_CHANNEL_SINGLETON_DECLARATION(T)
#  define OASIS_DATA_CHANNEL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* OASIS_DATA_CHANNEL_HAS_DLL == 1 */

// Set OASIS_DATA_CHANNEL_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (OASIS_DATA_CHANNEL_NTRACE)
#  if (ACE_NTRACE == 1)
#    define OASIS_DATA_CHANNEL_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define OASIS_DATA_CHANNEL_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !OASIS_DATA_CHANNEL_NTRACE */

#if (OASIS_DATA_CHANNEL_NTRACE == 1)
#  define OASIS_DATA_CHANNEL_TRACE(X)
#else /* (OASIS_DATA_CHANNEL_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define OASIS_DATA_CHANNEL_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (OASIS_DATA_CHANNEL_NTRACE == 1) */

#endif /* OASIS_DATA_CHANNEL_EXPORT_H */

// End of auto generated file.
