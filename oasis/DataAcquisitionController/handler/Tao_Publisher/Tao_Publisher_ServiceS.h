// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.1.2
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:461

#ifndef _TAO_IDL_TAO_PUBLISHER_SERVICES_VJZQQN_H_
#define _TAO_IDL_TAO_PUBLISHER_SERVICES_VJZQQN_H_

#include /**/ "ace/pre.h"

#include "Tao_Publisher_ServiceC.h"
#include "oasis/DataAcquisitionController/Remote_ServiceS.h"
#include "oasis/middleware/tao/Data_Channel/CommandChannelS.h"
#include "oasis/middleware/tao/OASIS_UUIDS.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#include /**/ "Tao_Publisher_Service_skel_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO OASIS_TAO_PUBLISHER_SERVICE_SKEL_Export

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:685

  template<>
  class SArg_Traits< ::OASIS::SoftwareProbeData>
    : public
        Var_Size_SArg_Traits_T<
            ::OASIS::SoftwareProbeData,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:947

  template<>
  class SArg_Traits< ::OASIS::SubscriberDataPacket>
    : public
        Var_Size_SArg_Traits_T<
            ::OASIS::SubscriberDataPacket,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_OASIS_DATASUBSCRIBER__SARG_TRAITS_)
#define _OASIS_DATASUBSCRIBER__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::OASIS::DataSubscriber>
    : public
        Object_SArg_Traits_T<
            ::OASIS::DataSubscriber_ptr,
            ::OASIS::DataSubscriber_var,
            ::OASIS::DataSubscriber_out,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_OASIS_PUBLISHERSERVICE__SARG_TRAITS_)
#define _OASIS_PUBLISHERSERVICE__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::OASIS::PublisherService>
    : public
        Object_SArg_Traits_T<
            ::OASIS::PublisherService_ptr,
            ::OASIS::PublisherService_var,
            ::OASIS::PublisherService_out,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// .\be\be_visitor_module\module_sh.cpp:38

namespace POA_OASIS
{
  

  // TAO_IDL - Generated from
  // .\be\be_visitor_interface\interface_sh.cpp:76

  class DataSubscriber;
  typedef DataSubscriber *DataSubscriber_ptr;

  class OASIS_TAO_PUBLISHER_SERVICE_SKEL_Export DataSubscriber
    : public virtual PortableServer::ServantBase
  {
  protected:
    DataSubscriber (void);
  
  public:
    /// Useful for template programming.
    typedef ::OASIS::DataSubscriber _stub_type;
    typedef ::OASIS::DataSubscriber_ptr _stub_ptr_type;
    typedef ::OASIS::DataSubscriber_var _stub_var_type;

    DataSubscriber (const DataSubscriber& rhs);
    virtual ~DataSubscriber (void);

    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

    virtual void _dispatch (
        TAO_ServerRequest & req,
        TAO::Portable_Server::Servant_Upcall *servant_upcall);
    
    ::OASIS::DataSubscriber *_this (void);
    
    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // .\be\be_visitor_operation\operation_sh.cpp:39

    virtual char * name (
      void) = 0;

    static void _get_name_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);

    // TAO_IDL - Generated from
    // .\be\be_visitor_operation\operation_sh.cpp:39

    virtual void handle_data (
      const ::OASIS::SubscriberDataPacket & packet) = 0;

    static void handle_data_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_interface\interface_sh.cpp:76

  class PublisherService;
  typedef PublisherService *PublisherService_ptr;

  class OASIS_TAO_PUBLISHER_SERVICE_SKEL_Export PublisherService
    : public virtual POA_OASIS::RemoteService
  {
  protected:
    PublisherService (void);
  
  public:
    /// Useful for template programming.
    typedef ::OASIS::PublisherService _stub_type;
    typedef ::OASIS::PublisherService_ptr _stub_ptr_type;
    typedef ::OASIS::PublisherService_var _stub_var_type;

    PublisherService (const PublisherService& rhs);
    virtual ~PublisherService (void);

    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

    virtual void _dispatch (
        TAO_ServerRequest & req,
        TAO::Portable_Server::Servant_Upcall *servant_upcall);
    
    ::OASIS::PublisherService *_this (void);
    
    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // .\be\be_visitor_operation\operation_sh.cpp:39

    virtual void register_subscriber (
      const ::OASIS::UUID & probe_uuid,
      ::OASIS::DataSubscriber_ptr subscriber) = 0;

    static void register_subscriber_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);

    // TAO_IDL - Generated from
    // .\be\be_visitor_operation\operation_sh.cpp:39

    virtual void unregister_subscriber (
      const ::OASIS::UUID & probe_uuid,
      ::OASIS::DataSubscriber_ptr subscriber) = 0;

    static void unregister_subscriber_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);
  };

// TAO_IDL - Generated from
// .\be\be_visitor_module\module_sh.cpp:69

} // module OASIS

#include /**/ "ace/post.h"

#endif /* ifndef */
