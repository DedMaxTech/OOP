#include "random_hypotenuse.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <fstream>

int main() {
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
    std::deque<double> new_deque;


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
        file << "|---|---|---|---|---|---|---|---|---|\n";

        auto it_src_list = src_list.begin();
        auto it_new_list = new_list.begin();

        for (int i = 0; i < M; i++) {
            file << "| " << i 
                 << " | " << src_array[i]
                 << " | " << src_vector[i] 
                 << " | " << *it_src_list
                 << " | " << src_deque[i] 
                 << " | " << new_array[i] 
                 << " | " << new_vector[i] 
                 << " | " << *it_new_list
                 << " | " << new_deque[i] << " |\n";

            it_src_list++;
            it_new_list++;
        }
        file.close();
    }


}
