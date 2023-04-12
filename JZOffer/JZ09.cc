/**
 * @file JZ09 用两个栈实现队列
 * @brief 队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 *      在队列尾部插入整数;
        在队列头部删除整数的功能(若队列中没有元素，deleteHead 操作返回 -1 );

    思路：栈 + 辅助栈（维护最小值）
 */

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

class CQueue {
public:
    CQueue() {
        helper_ = {};
        queue_ = {};
    }

    /**
     * @brief queue_ 为空时: 直接将 value 放入queue_
     * queue_.empty() 非空时:
            1. 将 queue_ 中元素取出放入 helper_
            2. 将 value 放入 helper_
            3. 将 helper_ 中元素取出并放入 queue_
     * @param value
     */
    void appendTail(int value) {
        if (queue_.empty()) {
            queue_.push(value);
        } else {
            while (!queue_.empty()) {
                helper_.push(queue_.top());
                queue_.pop();
            }

            helper_.push(value);

            while (!helper_.empty()) {
                queue_.push(helper_.top());
                helper_.pop();
            }
        }
    }

    /**
     * @brief queue_ 为空时： return -1；否则，返回 queue_.top()
     *
     * @return int
     */
    int deleteHead() {
        if (queue_.empty()) {
            return -1;
        } else {
            int ret = queue_.top();
            queue_.pop();
            return ret;
        }
    }

private:
    stack<int> helper_;
    stack<int> queue_;
};

int main() {
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);

    int param_2 = obj->deleteHead();

    cout << param_2 << endl;

    return 0;
}