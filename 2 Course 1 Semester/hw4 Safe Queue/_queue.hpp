//
//  _queue.hpp
//  hw4 Safe Queue
//
//  Created by Platon on 28.12.2017.
//  Copyright © 2017 Platon. All rights reserved.
//

#ifndef _queue_hpp
#define _queue_hpp

#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

class _queue {
private:
    std::mutex _mutex;
    std::queue<int> queue_;
public:
    _queue(){
        std::queue<int> b;
        queue_ = b;
    }
    _queue(int n){
        _mutex.lock();
        queue_.push(n);
        _mutex.unlock();
    }
    void push(int n){
        _mutex.lock();
        queue_.push(n);
        _mutex.unlock();
    }
    void size()
    {
        _mutex.lock();
        _mutex.unlock();
    }
    int front()
    {
        _mutex.lock();
        int _return = queue_.front();
        _mutex.unlock();
        return _return;
    }
    int back()
    {
        _mutex.lock();
        int _return = queue_.back();
        _mutex.unlock();
        return _return;
    }
    void pop(){
        
        _mutex.lock();
        if (!queue_.empty()){
            queue_.pop();
        }
        _mutex.unlock();
    }
    
    
    
};
#endif /* _queue_hpp */
