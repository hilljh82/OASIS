// $Id: Foo_Bridge.cpp 2211 2012-07-25 12:55:51Z dfeiock $

#include "Foo_Bridge.h"
#include "oasis/streams.h"
#include "oasis/probes/Software_Probe.h"
#include "oasis/probes/Software_Probe_Header.h"
#include "oasis/probes/Software_Probe_Data_Preparer.h"
#include "oasis/middleware/tena/bridges/Configuration_Exception.h"


namespace OASIS
{
  //
  // _create
  //
  ::OASIS::Software_Probe_Bridge * Foo_Bridge::_create (void)
  {
    ::OASIS::Software_Probe_Bridge * bridge = 0;
    ACE_NEW_RETURN (bridge,
                    Foo_Bridge (),
                    0);

    return bridge;
  }

  //
  // Foo_Bridge
  //
  Foo_Bridge::Foo_Bridge (void)
  {

  }

  //
  // ~Foo_Bridge
  //
  Foo_Bridge::~Foo_Bridge (void)
  {

  }

  //
  // create_servant
  //
  int Foo_Bridge::
  create_servant (const ACE_Utils::UUID & einode,
                  const ::OASIS::DAC::Software_Probe_Instance & inst)
  {
    // Make sure there is no servant already associated with this // instance.
    if (this->servants_.find (inst.ext_id_.c_str ()) != this->servants_.end ())
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - servant already exist for %s\n"),
                         inst.ext_id_.c_str ()),
                         -1);

    // Create the initializer for the new servant.
    std::auto_ptr < sdo_type::PublicationStateInitializer > initializer (this->factory_->createInitializer ());

    // Initialize the initial value trunk
    OASIS::Configuration_Member_Container * parent = 0;
    try
    {
      parent = &this->group_[inst.ext_id_];
    }
    catch (Invalid_Child & ex)
    {
      parent = 0;
    }

    // Initialize software probe bridge attributes.
    this->initialize_metadata (*initializer, einode, inst);

    // We are now ready to create the servant.
    this->servants_[inst.ext_id_.c_str ()] =
      this->factory_->createServant (*initializer, ::TENA::Middleware::Reliable);

    return 0;
  }

  //
  // publish
  //
  int Foo_Bridge::
  publish (const ::OASIS::DAC::Data_Packet & packet)
  {
    // Extract the base contents of the packet.
    OASIS::Software_Probe_Header probe;
    probe.recall (packet.probe_data (),
                  packet.probe_data_length (),
                  packet.byte_order ());

    // Locate the servant for this software probe instance.
    ServantPtr_Map::const_iterator iter =
      this->servants_.find (probe.name_);

    if (iter == this->servants_.end ())
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - servant does not exist for %s\n"),
                         probe.name_.c_str ()),
                         -1);

    // Locate the probe in the mapping.
    ::OASIS::Foo::ServantPtr servant = iter->second;

    if (!servant.isValid ())
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - invalid servant for %s\n"),
                         probe.name_.c_str ()),
                         -1);

    // Instantiate a new updater.
    std::auto_ptr < ::OASIS::Foo::PublicationStateUpdater >
      updater (servant->createUpdater ());

    // Update the servant values.
    Software_Probe_Data_Preparer prep (packet.probe_data (),
                                       packet.probe_data_length ());
    ACE_InputCDR input (prep.message_block (),
                        packet.byte_order ());

    if (0 != this->update (*updater, input))
      return -1;

    // We are now ready to commit the updater.
    servant->commitUpdater (updater);
    return 0;
  }

  //
  // update
  //
  int Foo_Bridge::
  update (PublicationStateUpdater & updater, ACE_InputCDR & input)
  {
    // Extract the contents from the base class.
    if (0 != ::OASIS::Software_Probe_Bridge::update (updater, input))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - failed to update base class\n")),
                         -1);

    return 0;
  }

}
