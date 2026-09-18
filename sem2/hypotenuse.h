#pragma once
#include <cmath>

namespace Normal {
	//double hypotenuse(const double& a, const double& b);
	//int hypotenuse(const int& a, const int& b);
	template <typename T>
	T hypotenuse(const T& a, const T& b) {
		return std::sqrt(a * a + b * b);
	}
}