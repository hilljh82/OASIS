// -*- C# -*-

//=============================================================================
/**
 * @file      Recall_Generator.h
 *
 *  $Id: Recall_Generator.h 2118 2012-01-13 20:29:17Z dpuranik $
 *
 *  @author   Darshan Puranik
 */
//=============================================================================

#ifndef _OASIS_PDL_BE_CSHARP_RECALL_GENERATOR_H_
#define _OASIS_PDL_BE_CSHARP_RECALL_GENERATOR_H_

#include "fe/PDL_Visitor.h"
#include <ostream>

namespace OASIS_PDL_BE
{
namespace Csharp
{

/**
 * @class Recall_Generator
 *
 * Visitor that generates the packaging implementation.
 */
class Recall_Generator : public OASIS_PDL_Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       out       Target output stream.
   */
  Recall_Generator (std::ostream & csfile);

  /// Destructor.
  virtual ~Recall_Generator (void);

  virtual void visit_probe (const OASIS_PDL_Probe & p);

  virtual void visit_complex_type_member (const OASIS_PDL_Complex_Type_Member & );

  virtual void visit_struct (const OASIS_PDL_Struct & s);

  virtual void visit_simple_type (const OASIS_PDL_Simple_Type & s);

  bool find(std::string type);

private:

  /// Target source file stream.
  std::ostream & csfile_;

  /// We are generating types for probes.
  bool is_probe_;

  /// Creating this to differentiate betn struct and basic types
  static const std::string basic_types[12];
};

}
}

#endif  // !defined _OASIS_PDL_BE_CSHARP_VAR_TYPE_GENERATOR_H_
