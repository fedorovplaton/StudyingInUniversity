//
//  main.cpp
//  hw7 MultiThreadVector
//
//  Created by Platon on 25.12.17.
//  Copyright © 2017 Platon. All rights reserved.
//

#include <thread>
#include <vector>
#include <string>
#include <list>
#include <sstream>
#include "thread_vector.hpp"
#include "atomic_vector.hpp"

using namespace std;

atomic_vector<string> b;
//thread_vector<string> a;


void foo(string c)
{
    //cout << 5;
    auto id = this_thread::get_id();
    stringstream ss;
    ss << id;
    string mystring = ss.str();
    cout << mystring << '\n';
    b.push_back(mystring);
    b.push_back(c);
    //cout << b;
    cout << '\n';
    return;
}

int main(int argc, const char * argv[]) {
    
    b.push_back("start");
    thread* arr = new thread[5];
    for (unsigned i = 0; i < 5; i++) {
        arr[i] = thread(foo, "hello");
    }
    for (unsigned i = 0; i < 5; i++) {
        arr[i].join();
    }
    int d = b._size();
    for(int i = 0; i < d; i++)
        cout << b[i] << '\n';
    b.push_back("end");
    delete [] arr;
    return 0;
}
