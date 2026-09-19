#include "hypotenuse.h"
#include "random_hypotenuse.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <fstream>

int main() {
    //int a, b;
    //std::cout << "a b: ";
    //std::cin >> a >> b;
    //std::cout << "hypotenuse: " << Normal::hypotenuse<int, double>(a, b) << '\n';
    //std::cout << "modified: " << Random::hypotenuse<double, int>(a, b) << '\n';

    //std::unique_ptr<int> ptr = std::make_unique<int>(1234);

    //int size = 10;
    ////int* arr = new int[size];
    //std::unique_ptr<int[]> arr = std::make_unique<int[]>(size);


    //for (int i = 0; i < size; i++) {
    //    std::cin >> arr[i];
    //}
    //for (int i = 0; i < size; i++) {
    //    std::cout << arr[i] << ' ';
    //}

    ////int* demo = new int(1234);
    ////delete demo;
    ////std::cout << "\nptr " << demo << ' ' << *demo << '\n';
    ////demo = nullptr;
    //std::unique_ptr<int> demo = std::make_unique<int>(1234);
    //demo.reset();
    //std::cout << "\nptr " << demo << ' ' << *demo << '\n';

    //int mid = size / 2;
    //std::unique_ptr<int[]> buf = std::make_unique<int[]>(size+1);
    //for (int i = 0; i < mid; i++) buf[i] = arr[i];
    //buf[mid] = 1234;
    //for (int i = mid; i < size; i++) buf[i+1] = arr[i];

    //arr = std::move(buf);
    //size++;
    //for (int i = 0; i < size; i++) {
    //    std::cout << arr[i] << ' ';
    //}


    ////delete[] arr;
    ////delete ptr;
    ////ptr = nullptr;

    const int M = 5;
    const int N = 50;
    static std::mt19937 gen(std::random_device{}());
    static std::uniform_int_distribution<int> number(-N, N);

    std::array<int, M> src_array;
    std::vector<int> src_vector(M);
    std::list<int> src_list;
    std::deque<int> src_deque(M);

    for (int i = 0; i < M; i++) {
        src_array[i] = number(gen);
        src_vector[i] = number(gen);
        src_list.push_back(number(gen));
        src_deque[i] = number(gen);
    }

    std::array<double, M> new_array;
    std::vector<double> new_vector(M);
    std::list<double> new_list;
    std::deque<double> new_deque(M);


    int num = number(gen);
    for (int i = 0; i < M; i++) {
        new_array[i] = Random::hypotenuse<int, double>(src_array[i], num);
        new_vector[i] = Random::hypotenuse<int, double>(src_vector[i], num);
    }

    
    for (auto it = src_list.begin(); it != src_list.end(); it++)
        new_list.push_back(*it);

    for (const auto& val : src_deque)
        new_deque.push_back(val);

    std::ofstream file("table.md");
    if (file.is_open()) {
        file << "| IDX | src_array | src_vector | src_list | src_deque | new_array | new_vector | new_list | new_deque |\n";
        for (int i = 0; i < M; i++) file << "| " << i << " | " << src_vector[i] << " | " << src_array[i] << " | " << src_list[i] << " | " << 
    }


}
