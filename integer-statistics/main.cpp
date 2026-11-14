#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> vec;
    int number;
   
    while (std::cin >> number && number != 0)
    {
        vec.push_back(number);
    }

    std::cout << "Liczba elementow: " << vec.size() << std::endl;


    std::vector<int>::iterator min = std::min_element(vec.begin(), vec.end());
    std::vector<int>::iterator max = std::max_element(vec.begin(), vec.end());
    std::cout << "minimalny element to: " << *min << " \nmaksymalny element to: " << *max << std::endl;

    std::sort(vec.begin(), vec.end(), [](int a, int b) {
    return a < b;});

    std::cout << "Posortowane rosnaco: ";
    for (const auto& elem : vec) {
    std::cout << elem << " ";
    }
    std::cout << std::endl;


    struct Desc {
    bool operator()(int a, int b) const { return a > b; }
    };
    std::sort(vec.begin(), vec.end(), Desc());
    std::cout << "Posortowane malejaco: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
   

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) {
        return x < 0;
    }), vec.end());

    std::cout << "Po usunieciu liczb ujemnych: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}