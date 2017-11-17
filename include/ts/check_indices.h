#ifndef _METACOL_TS_CHECK_INDICES_H_
#define _METACOL_TS_CHECK_INDICES_H_

#include "range.h"
#include "conjunction.h"

namespace mco {

template <typename T, int I>
struct check_indices;

template <template <int...> class C, int I, int... Indices>
struct check_indices<C<Indices...>, I>  : conjunction<std::integral_constant<bool, Indices < I>...> {};

} /* namespace mco */

/*
Usage :
#include "range.h"

int main()
{
  static_assert( check_indices<make_int_sequence<2>, 3>::value, "All indices are less than 3.");
  return 0;
}
*/

#endif /* _METACOL_TS_CHECK_INDICES_H_ */