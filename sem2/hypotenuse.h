#pragma once
#include <cmath>

namespace Normal {
	//double hypotenuse(const double& a, const double& b);
	//int hypotenuse(const int& a, const int& b);
	template <typename T, typename K>
	T hypotenuse(const T& a, const T& b) {
		return static_cast<K>(std::sqrt(a * a + b * b));
	}
}