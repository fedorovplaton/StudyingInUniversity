//
//  main.cpp
//  hw6_CustomAtomic
//
//  Created by Platon on 25.12.17.
//  Copyright © 2017 Platon. All rights reserved.
//

#include "custom_atomic.hpp"
#include <iostream>
#include <thread>
#include <vector>

void foo(custom_atomic<int> a)
{
    while(a.load() < 22){
        int b = a.load();
        a = b + 1;
        std::cout << std::thread::id() << "up to " << b+1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    custom_atomic<int> a;
    custom_atomic<int> b(5);
    a = b;
    std::vector <std::thread> Threads;
    for(int i = 0; i < 3; i++)
        Threads.push_back(std::thread(foo, a));
    //vec_thr.push_back(thr1);
    return 0;
}
