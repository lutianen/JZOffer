/**
 * @file Singleton 单例模式
 * @brief 1. 静态指针变量私有化 -> 指向唯一实例
 *        2. 静态锁 -> 静态函数只能访问静态成员
 *        3. 构造函数私有化 -> 防止多次创建实例
 *        4. 双层检测
 * --------------------------------------------------
 * 局部静态变量之线程安全懒汉模式
 * 函数内局部静态对象，不用加锁和解锁操作。
 * C++ 保证，函数内的 local static 对象会在“该函数被调用期间” “首次遇上该对象之定义式”时被初始化，以后的函数调用不再进行初始化。
 * 
 */


#include <iostream>
#include <pthread.h>

using std::cout;
using std::endl;


// -------------------------------------------------------------
// 双层检测
class Singleton {
private:
    // 私有静态指针变量指向唯一实例
    // 不占用类空间
    static Singleton* p_;

    // 静态锁，因为静态函数只能访问静态成员
    static pthread_mutex_t lock_;

    // 构造函数私有化
    Singleton() { pthread_mutex_init(&lock_, nullptr); }


    ~Singleton() {}
public:
    static Singleton* getInstance();
};

pthread_mutex_t Singleton::lock_;
Singleton *Singleton::p_ = nullptr;

/**
 * @brief 为什么需要双检测，只检测一次不i行吗？
 *  如果只检测一次，在每次调用实例的方法时，都需要加锁，这将严重影响程序性能。
 *  双检测可有有效避免这种情况，仅在第一次创建单例时加锁，
 *      其他时候不在符合 `nullptr == p_` 的情况，直接返回已创建好的实例。
 * @return Singleton* 
 */
Singleton *Singleton::getInstance() {
    if (nullptr == p_) {
        pthread_mutex_lock(&lock_);
        if (nullptr == p_) {
            p_ = new Singleton;
        }

        pthread_mutex_unlock(&lock_);
    }

    return p_;
}

// -------------------------------------------------------------
// 局部静态变量之线程安全懒汉模式
// 函数内局部静态对象，不用加锁和解锁操作
class SingletonLazy {
private:
    SingletonLazy() {}
    ~SingletonLazy() {}

public:
    static SingletonLazy* getInstance();
};

/**
 * @brief C++ 保证，函数内的 local static 对象会在“该函数被调用期间”“首次遇上该对象之定义式”时被初始化。
 *   所以如果你以“函数调用”（返回一个 reference 指向 local static 对象）
 *   替换“直接访问 non-local static 对象”，你就获得了保证，保证你所获得的那个
 *   reference 将指向一个经历初始化的对象
 * 
 * @return SingletonLazy* 
 */
SingletonLazy* SingletonLazy::getInstance() {
    static SingletonLazy obj;
    return &obj;
}
// -------------------------------------------------------------


int main () {
    cout << sizeof(Singleton) << endl;
    Singleton* single = Singleton::getInstance();
    cout << sizeof(single) << endl;

    return 0;
}

