//
//  cpp智能指针.hpp
//  C++_xcode
//
//  Created by 韩霄 on 2021/4/21.
//

#ifndef cpp_____hpp
#define cpp_____hpp

#include <stdio.h>

//共享计数的智能指针 shared_ptr为代表
//首先写共享计数的借口
class shared_count{
public:
    shared_count();
    void add_count();
    //当减少计数的时候，最后返回当前的计数值，提供后面判断是否需要释放内存资源
    long reduce_count();
    long get_count() const; //获取常量的函数，保险起见，加上const
   
private:
    long count_;
};



//下面是重点来了，手写智能指针smart_ptr
template <typename T>
class smart_ptr {
public:
//C++中的关键字explicit主要是用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显示的方式进行类型转换。类构造函数默认情况下声明为隐式的即implicit。
//    explicit只能用于类内部的构造函数声明上，不能用于类外部的函数定义上！！
    explicit smart_ptr (T* ptr = nullptr): ptr_(ptr){
        if(ptr){
            shared_count_ = new shared_count();
        }
    }
    ~smart_ptr(){
        if(ptr_ && !shared_count_-> reduce_count()){
            //把两个指针都删除，防止内存泄漏。
            delete ptr_;
            delete shared_count_;
        }
    }
    
    void  swap(smart_ptr& rhs){
        using namespace std;
        swap(ptr_,rhs.ptr_);
        swap(shared_count_,rhs.shared_count_);
    }
    
    //赋值函数
    
    
    //拷贝构造函数
    
    //移动构造函数
    
private:
    T* ptr_;
    shared_count* shared_count_;
};


#endif /* cpp_____hpp */
