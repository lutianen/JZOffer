/**
 * @file JZ15 二进制中1的个数
 * @brief 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）

    思路：右移位判断最低位
 */

#include <cstdint>
#include <iostream>

class Solution {
public:
    /**
     * @brief res += ((n >> i) & 1) == 1 ? 1 : 0; // 利用右移，逐位判断最低位是否为1
     * 
     * @param n 
     * @return int 
     */
    int hammingWeight(uint32_t n) {
        int res = 0;
        
        for(int i = 0; i < 32; ++i) {
            res += ((n >> i) & 1) == 1 ? 1 : 0;
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::cout << s.hammingWeight(128) << std::endl;
    std::cout << s.hammingWeight(129) << std::endl;
    std::cout << s.hammingWeight(130) << std::endl;
    std::cout << s.hammingWeight(131) << std::endl;
}
