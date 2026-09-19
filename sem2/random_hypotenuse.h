#pragma once
#include <random>

namespace Random {
	//double hypotenuse(double a, double b);
	//int hypotenuse(int a, int b);
    template <typename T, typename K>
    T hypotenuse(const T& a, const T& b) {
        static std::mt19937 gen(std::random_device{}());
        static std::bernoulli_distribution add(0.5);
        static std::uniform_real_distribution number(1.0, 10.0);
        K result = Normal::hypotenuse<T, K>(a, b);
        return add(gen) ? result + static_cast<K>(number(gen)) : result;
    }
}