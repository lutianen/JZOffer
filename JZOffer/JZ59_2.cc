/**
 * @file JZ59_2 队列的最大值
 * @brief 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
        若队列为空，pop_front 和 max_value 需要返回 -1

    链接：https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof

    思路：单调双向队列
        构建一个辅助单调不增双向队列（单调双向队列）来保存队列所有递减的元素 ，递减队列随着入队和出队操作实时更新，
        这样队列最大元素就始终对应递减列表的首元素，实现了获取最大值 O(1) 时间复杂度

 */
#include <deque>
#include <queue>
#include <iostream>

using std::deque;
using std::queue;

class MaxQueue {
public:
    MaxQueue() {
        que_ = {};
        deQ_ = {};
    }
    
    int max_value() {
        if (deQ_.empty())
            return -1;
        else return deQ_.front();
    }
    
    void push_back(int value) {
        que_.push(value);
        if (deQ_.empty())
            deQ_.push_back(value);
        else if (value <= deQ_.back())
            deQ_.push_back(value);
        else {
            while(!deQ_.empty() && deQ_.back() <= value) {
                deQ_.pop_back();
            }

            deQ_.push_back(value);
        }
    }
    
    int pop_front() {
        if (que_.empty() || deQ_.empty())
            return -1;
        
        int v = que_.front();
        if (v == deQ_.front()){
            deQ_.pop_front();
        }

        que_.pop();
        return v;
    }

private:
    queue<int> que_;
    deque<int> deQ_;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {
    MaxQueue q;
    std::cout << q.max_value() << std::endl;
    q.push_back(1);
    q.push_back(2);
    std::cout << q.max_value() << std::endl;
    std::cout << q.pop_front() << std::endl;
    std::cout << q.max_value() << std::endl;
}