//
//  custom_atomic.hpp
//  hw6_CustomAtomic
//
//  Created by Platon on 25.12.17.
//  Copyright © 2017 Platon. All rights reserved.
//

#ifndef custom_atomic_hpp
#define custom_atomic_hpp

#include <mutex>
#include <stdio.h>

template <class T>
class custom_atomic{
    T _data;
    std::mutex _mutex;
public:
    custom_atomic()
    {
        _data = T();
    }
    custom_atomic(T data)
    {
        _data = data;
    }
    ~custom_atomic()
    {
        
    }
    T load()
    {
        T _return;
        _mutex.lock();
        _return = _data;
        _mutex.unlock();
        return _return;
    }
    void store(T data)
    {
        _mutex.lock();
        _data = data;
        _mutex.unlock();
    }
    T exchange(T data){
        T _result;
        _mutex.lock();
        _result = _data;
        _data = data;
        _mutex.unlock();
    }
    bool is_lock_free()
    {
        return _mutex.try_lock();
    }
    operator T()
    {
        _mutex.lock();
        T _return = _data;
        _mutex.unlock();
        return _return;
    }
    custom_atomic &operator= (const T &desired)
    {
        _mutex.lock();
        _data = desired;
        _mutex.unlock();
        return *this;
    }
    custom_atomic &operator= (const custom_atomic <T> &desired)
    {
        _mutex.lock();
        _data = desired._data;
        _mutex.unlock();
        return *this;
    }
};

#endif /* custom_atomic_hpp */
