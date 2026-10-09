#pragma once
#include <cmath>

namespace Normal {
template <typename T, typename K>
K hypotenuse(const T& a, const T& b) {
    return static_cast<K>(std::hypot(static_cast<double>(a), static_cast<double>(b)));
}
}
