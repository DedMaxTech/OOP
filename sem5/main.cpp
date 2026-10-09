#include "hypotenuse.h"
#include "random_hypotenuse.h"
#include <iostream>

int main() {
    int a, b;
    std::cout << "a b: ";
    if (!(std::cin >> a >> b)) {
        return 1;
    }
    std::cout << "hypotenuse: " << Normal::hypotenuse<int, double>(a, b) << '\n';
    std::cout << "modified: " << Random::hypotenuse<double, int>(a, b) << '\n';
}
