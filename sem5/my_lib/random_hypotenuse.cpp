#include "random_hypotenuse.h"
#include "hypotenuse.h"

namespace Random {
    /*template <typename T>
    T hypotenuse(const T& a, const T& b) {
        static std::mt19937 gen(std::random_device{}());
        static std::bernoulli_distribution add(0.5);
        static std::uniform_int_distribution<T> number(1, 10);
        T result = Normal::hypotenuse<T>(a, b);
        return add(gen) ? result + number(gen) : result;
    }*/
    //int hypotenuse(const int& a, const int& b) {
    //    return static_cast<int>(hypotenuse(static_cast<double>(a), static_cast<double>(b)));
    //}
}
