#include <iostream>
#include <vector>

int main() {
    {
        std::vector<int> vec_a;
        std::cout << vec_a.size() << ", " << vec_a.capacity() << std::endl;

        vec_a.reserve(10);
        std::cout << vec_a.size() << ", " << vec_a.capacity() << std::endl;

        std::cout << __LINE__ << ": ";
        for (const auto& e : vec_a) std::cout << e << " ";
        std::cout << std::endl;

        vec_a.resize(16);
        std::cout << vec_a.size() << ", " << vec_a.capacity() << std::endl;

        std::cout << __LINE__ << ": ";
        for (const auto& e : vec_a) std::cout << e << " ";
        std::cout << std::endl;
    }
}