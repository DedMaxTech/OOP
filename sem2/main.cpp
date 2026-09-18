#include "hypotenuse.h"
#include "random_hypotenuse.h"
#include <iostream>

int main() {
    int a, b;
    std::cout << "a b: ";
    std::cin >> a >> b;
    std::cout << "hypotenuse: " << Normal::hypotenuse(a, b) << '\n';
    std::cout << "modified: " << Random::hypotenuse(a, b) << '\n';
}
