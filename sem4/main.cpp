#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> vec1;
    std::ifstream file1("s04_v1_45_1.txt");
    if (file1.is_open()) {
        int temp;
        while (file1 >> temp) {
            vec1.push_back(temp);
            file1.get();
        }
        file1.close();
    }
    std::vector<int> vec2;
    std::ifstream file2("s04_v1_45_2.txt");
    if (file2.is_open()) {
        int temp;
        while (file2 >> temp) {
            vec2.push_back(temp);
            file2.get();
        }
        file2.close();
    }
    std::cout << "vec1 len=" << vec1.size() << " vec2 len=" << vec2.size() << '\n';

    std::map<int, int> counts;
    for (const int& i : vec1) {
        counts[i]++;
    }
    for (const auto [i, count] : counts) {
        std::cout << i << ':' << count << ", ";
    }
    std::cout << '\n';

    std::set<int> set(vec2.begin(), vec2.end());
    for (const int& i : set) 
        std::cout << i << ':' << std::count(vec2.begin(), vec2.end(), i) << ", ";
    std::cout <<'\n';


    int sum_vec1 = std::accumulate(vec1.begin(), vec1.end(), 0);

    int sum_vec2 = 0;
    std::for_each(vec2.begin(), vec2.end(), [&sum_vec2](int i) {sum_vec2 += i;});

    std::cout << "sum vec1=" << sum_vec1 << " sum vec2=" << sum_vec2 << '\n';

    int sum_first_vec1 = std::accumulate(vec1.begin(), vec1.begin() + 10, 0);

    std::vector<int>::iterator first10 = vec2.begin();
    std::advance(first10, 10);
    int sum_first_vec2 = std::accumulate(vec2.begin(), first10, 0);
    std::cout << "sum 10 vec1=" << sum_first_vec1 << " sum 10 vec2=" << sum_first_vec2 << '\n';

}
