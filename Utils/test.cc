#include <iostream>
#include <vector>
#include <pthread.h>

std::vector<int> func(int a) {
    std::cout << __FUNCTION__ << std::endl;
    return {};
}

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
    {
        int i = 0;
        // ++i 是左值
        ++i = 10;

        // "01234" 是左值，且类型为 const char [6]
        const char(&left)[6] = "01234";

        /*
            decltype(expr) 在 expr 为左值且非无括号包裹的 id
           表达式与类成员表达式时，会返回左值引用
        */
        static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value,
                      "");
        static_assert(std::is_same<decltype("01234"), decltype(left)>::value,
                      "");
        // const char(&&right)[6] = "01234"; // "01234" 是左值，不可被 右值引用
    }
    {
        func(1);
        
    }
}