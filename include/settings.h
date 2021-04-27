#ifndef LBM_SETTINGS_H_
#define LBM_SETTINGS_H_

#include <type_traits>
#include <typeinfo>

namespace lbm {
//! Define single or double precision
using Real = double;
//! Switch between 64bit and 32bit integers
using Lint = long long;
}  // namespace lbm

#endif  // LBMDEM_SETTINGS_H_
