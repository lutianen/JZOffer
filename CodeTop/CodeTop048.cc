/**
 * @brief 最小栈
 * @link https://leetcode.cn/problems/min-stack/
 */

#include <iostream>
#include <memory>
#include <stack>

using std::stack;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        stk_.push(val);
        if (hlp_.empty())
            hlp_.push(val);
        else
            hlp_.push(val < hlp_.top() ? val : hlp_.top());
    }

    void pop() {
        if (!stk_.empty()) {
            stk_.pop();
            hlp_.pop();
        }
    }

    int top() {
        if (!stk_.empty()) return stk_.top();
        return -1;
    }

    int getMin() {
        if (!hlp_.empty()) return hlp_.top();
        return -1;
    }

private:
    stack<int> stk_;
    stack<int> hlp_;
};

int main() {
    std::unique_ptr<MinStack> obj(new MinStack());
    int val = 0;
    obj->push(val);
    obj->pop();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    std::cout << obj->top() << std::endl;
    std::cout << obj->getMin() << std::endl;
}
