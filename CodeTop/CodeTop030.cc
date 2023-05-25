/**
 * @brief 用栈实现队列
 * @link https://leetcode.cn/problems/implement-queue-using-stacks/
 */

#include <iostream>
#include <memory>
#include <stack>

class MyQueue {
private:
    std::stack<int> helper_;
    std::stack<int> queue_;

public:
    MyQueue() : helper_(), queue_() {}

    void push(int x) {
        if (queue_.empty()) {
            queue_.push(x);
        } else {
            while (!queue_.empty()) {
                helper_.push(queue_.top());
                queue_.pop();
            }

            queue_.push(x);
            while (!helper_.empty()) {
                queue_.push(helper_.top());
                helper_.pop();
            }
        }
    }

    int pop() {
        int res = -1;
        if (!queue_.empty()) {
            res = queue_.top();
            queue_.pop();
        }

        return res;
    }

    int peek() {
        if (!queue_.empty()) {
            return queue_.top();
        }

        return -1;
    }

    bool empty() { return queue_.empty(); }
};

int main() {
    std::unique_ptr<MyQueue> obj(new MyQueue);

    obj->push(9);
    obj->push(5);
    obj->push(2);
    obj->push(7);

    std::cout << obj->pop() << std::endl;
    std::cout << obj->peek() << std::endl;
    std::cout << obj->empty() << std::endl;

    return 0;
}