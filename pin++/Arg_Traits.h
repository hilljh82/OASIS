// -*- C++ -*-

//==============================================================================
/**
 *  @file        arg_types.h
 *
 *  $Id: Arg_Traits.h 2305 2013-10-07 03:23:23Z hillj $
 *
 *  @author      Dennis Feiock
 */
//==============================================================================

#ifndef _OASIS_PIN_ARG_H_
#define _OASIS_PIN_ARG_H_

#include "pin.H"

namespace OASIS
{
namespace Pin
{

class Context;
class Const_Context;

/**
 * @struct Arg_T
 *
 * Struct for converting PIN IARG_TYPEs to their parameter types
 */
template <IARG_TYPE T>
struct Arg_T { };

#define DEFINE_IARG_PARAM_TYPE(IARG, PARAM_TYPE) \
  template < > \
  struct Arg_T <IARG> { \
    typedef PARAM_TYPE param_type; \
  }

DEFINE_IARG_PARAM_TYPE (::IARG_INST_PTR, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_THREAD_ID, THREADID);

DEFINE_IARG_PARAM_TYPE (::IARG_REG_REFERENCE, PIN_REGISTER *);
DEFINE_IARG_PARAM_TYPE (::IARG_REG_VALUE, ADDRINT);

DEFINE_IARG_PARAM_TYPE (::IARG_MEMORYREAD_EA, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_MEMORYREAD2_EA, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_MEMORYWRITE_EA, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_MEMORYREAD_SIZE, UINT32);
DEFINE_IARG_PARAM_TYPE (::IARG_MEMORYWRITE_SIZE, UINT32);
DEFINE_IARG_PARAM_TYPE (::IARG_MULTI_MEMORYACCESS_EA, PIN_MULTI_MEM_ACCESS_INFO *);

DEFINE_IARG_PARAM_TYPE (::IARG_CONTEXT, Context &);
DEFINE_IARG_PARAM_TYPE (::IARG_CONST_CONTEXT, Const_Context &);

DEFINE_IARG_PARAM_TYPE (::IARG_MEMORYOP_EA, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_MEMORYOP_MASKED_ON, BOOL);
DEFINE_IARG_PARAM_TYPE (::IARG_TSC, UINT64);

// Function arguments
DEFINE_IARG_PARAM_TYPE (::IARG_FUNCARG_CALLSITE_REFERENCE, ADDRINT *);
DEFINE_IARG_PARAM_TYPE (::IARG_FUNCARG_CALLSITE_VALUE, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_FUNCARG_ENTRYPOINT_VALUE, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_FUNCARG_ENTRYPOINT_REFERENCE, ADDRINT *);
DEFINE_IARG_PARAM_TYPE (::IARG_FUNCRET_EXITPOINT_VALUE, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_FUNCRET_EXITPOINT_REFERENCE, ADDRINT *);

// Syscall stuff
DEFINE_IARG_PARAM_TYPE (::IARG_SYSCALL_NUMBER, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_SYSARG_REFERENCE, ADDRINT *);
DEFINE_IARG_PARAM_TYPE (::IARG_SYSARG_VALUE, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_SYSRET_VALUE, ADDRINT);
DEFINE_IARG_PARAM_TYPE (::IARG_SYSRET_ERRNO, INT32);

} // namespace Pin
} // namespace OASIS

#endif  // _OASIS_PIN_ARG_H_