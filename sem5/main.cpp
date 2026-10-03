#include "hypotenuse.h"
#include "random_hypotenuse.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <fstream>
#include <memory>

int main() {
    int a, b;
    std::cout << "a b: ";
    std::cin >> a >> b;
    std::cout << "hypotenuse: " << Normal::hypotenuse<int, double>(a, b) << '\n';
    std::cout << "modified: " << Random::hypotenuse<double, int>(a, b) << '\n';

    std::unique_ptr<int> ptr = std::make_unique<int>(1234);

    int size = 10;
    //int* arr = new int[size];
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(size);


    for (int i = 0; i < size; i++) {
       std::cin >> arr[i];
    }
    for (int i = 0; i < size; i++) {
       std::cout << arr[i] << ' ';
    }

    //int* demo = new int(1234);
    //delete demo;
    //std::cout << "\nptr " << demo << ' ' << *demo << '\n';
    //demo = nullptr;
    std::unique_ptr<int> demo = std::make_unique<int>(1234);
    demo.reset();
    std::cout << "\nptr " << demo.get() << '\n';

    int mid = size / 2;
    std::unique_ptr<int[]> buf = std::make_unique<int[]>(size+1);
    for (int i = 0; i < mid; i++) buf[i] = arr[i];
    buf[mid] = 1234;
    for (int i = mid; i < size; i++) buf[i+1] = arr[i];

    arr = std::move(buf);
    size++;
    for (int i = 0; i < size; i++) {
       std::cout << arr[i] << ' ';
    }


    //delete[] arr;
    //delete ptr;
    //ptr = nullptr;
}
