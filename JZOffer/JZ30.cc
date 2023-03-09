/**
 * @file JZ30 包含min函数的栈
 * @brief 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
    调用 min、push 及 pop 的时间复杂度都是 O(1)。

    思路：利用两个栈实现
        一个 stack_ 正常存储数据
        另一个 minStack_ 用来存储当前栈中的最小值，且与 stack_ 中的元素数量相同(除了第一个INT_MAX)
 */

#include <iostream>
#include <stack>
#include <climits>

using std::stack;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack_ = {};
        minStack_.push(INT_MAX);
    }
    
    void push(int x) {
        if(minStack_.empty()) {
            minStack_.push(x);
        } else {
            minStack_.push((x > minStack_.top()) ? minStack_.top() : x);
        }
        
        stack_.push(x);
    }
    
    void pop() {
        if (stack_.empty())
            return;
        stack_.pop();
        minStack_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int min() {
        return minStack_.top();
    }

private:
    stack<int> stack_;
    stack<int> minStack_;
};

int main() {
    MinStack* s = new MinStack();
    s->push(12);
    s->push(2);
    std::cout << "top: " << s->top() << std::endl;
    std::cout << "min: " << s->min() << std::endl;
    s->pop();
    s->pop();
    std::cout << "min: " << s->min() << std::endl;
}