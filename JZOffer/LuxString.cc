/**
 * @file LuxString 
 * @brief 
    - default constructor
    - constructor with parameters
    - copy constructor
    - move constructor
    - copy assignment constructor
    - move assignment constructor
    - destructor
 */

#include <iostream>
#include <cstring>

class LuxString {
private:
    char* buffer_;
    size_t size_;

public:
    /// default constructor
    /// 委托构造
    LuxString() : LuxString("") {
        std::cout << "This is default constructor. " << std::endl;
    }

    /// constructor with parameters
    LuxString(const char* str) : buffer_(new char[std::strlen(str) + 1]), 
            size_(std::strlen(str)) {
        std::strcpy(buffer_, str);
        std::cout << "This is constructor with parameters. " << std::endl;
    }
    /// copy constructor
    LuxString(const LuxString& that) : buffer_(new char[that.size_ + 1]),
            size_(that.size_) {
        std::strcpy(buffer_, that.buffer_);
        std::cout << "This is copy constructor. " << std::endl;
    }
    /// move constructor
    LuxString(LuxString&& that) : buffer_(that.buffer_), size_(that.size_){
        that.buffer_ = nullptr;
        that.size_ = 0;
        std::cout << "This is move constructor. " << std::endl;
    }
    /// copy assignment constructor
    LuxString& operator= (const LuxString& that) {
        if (this != &that) {
            char* newBuf = new char[that.size_ + 1];
            std::strcpy(newBuf, that.buffer_);
            delete [] buffer_;
            buffer_ = newBuf;
            size_ = that.size_;
        }
        std::cout << "This is copy assignment constructor. " << std::endl;

        return *this;
    }
    /// move assignment constructor
    LuxString& operator= (LuxString&& that) {
        if (this != &that) {
            delete [] buffer_;
            buffer_ = that.buffer_;
            size_ = that.size_;

            that.buffer_ = nullptr;
            that.size_ = 0;
        }
        std::cout << "This is move assignment constructor. " << std::endl;

        return *this;
    }
    
    ~LuxString() {
        if (buffer_ != nullptr) {
            delete [] buffer_;
            size_ = 0;
            
            std::cout << "This is destructor. " << std::endl;
        }
        
    }

    size_t size() const { return size_; }
    const char* c_str() const { return buffer_; }
};

int main() {
    LuxString s1;
    std::cout << s1.size() << std::endl;

    LuxString s2 {"Lux"};
    std::cout << s2.c_str() << std::endl;

    LuxString s3 (s2);
    std::cout << s3.c_str() << std::endl;

    LuxString s4 (std::move(s2));
    std::cout << s4.c_str() << std::endl;

    LuxString s5;
    s5 = s3;
    std::cout << s5.c_str() << std::endl;

    LuxString s6;
    s6 = std::move(s5);
    std::cout << s6.c_str() << std::endl;
}