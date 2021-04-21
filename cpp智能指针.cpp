//
//  cpp智能指针.cpp
//  C++_xcode
//
//  Created by 韩霄 on 2021/4/21.
//

#include "cpp智能指针.hpp"



shared_count::shared_count():count_(1){};

void shared_count::add_count(){
    ++count_;
}

long shared_count::reduce_count(){
    --count_;
    return count_;
}

long shared_count::get_count() const {
    return count_;
}
