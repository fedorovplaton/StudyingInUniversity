//
//  atomic_vector.hpp
//  hw7 MultiThreadVector
//
//  Created by Platon on 25.12.17.
//  Copyright © 2017 Platon. All rights reserved.
//

#ifndef atomic_vector_hpp
#define atomic_vector_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <mutex>

template <class T>
class atomic_vector{
private:
    T *array;
    int array_size;
    int realsize;
public:
    std::mutex _mutex;
    atomic_vector()
    {
        array_size = 0;
        realsize = 0;
        array = new T[array_size];
    }
    int _size(){
        return array_size;
    }
    atomic_vector(atomic_vector &Another)
    {
        Another._mutex.lock();
        _mutex.lock();
        this->array_size = Another.size();
        realsize = Another.real_size();
        array = new T[realsize];
        for(int i = 0 ;i < realsize; i++)
            array[i] = Another[i];
        Another._mutex.unlock();
        _mutex.unlock();
    }
    
    ~atomic_vector()
    {
        _mutex.lock();
        delete [] array;
        _mutex.unlock();
    }
    
    int size()
    {
        _mutex.lock();
        return array_size;
        _mutex.unlock();
    }
    
    int real_size()
    {
        _mutex.lock();
        return realsize;
        _mutex.unlock();
    }
    
    T operator[](int index)
    {
        _mutex.lock();
        T _return;
        if(index >= 0 && index < array_size)
            _return = array[index];
        else
            std::cout << "Error: Out of the array" << '\n';
        _mutex.unlock();
        return _return;
    }
    
    friend void swap(atomic_vector &a, atomic_vector &b)
    {
        using std::swap;
        a._mutex.lock();
        b._mutex.lock();
        swap(a.array_size, b.array_size);
        swap(a.realsize, b.realsize);
        swap(a.array, b.array);
        a._mutex.unlock();
        b._mutex.unlock();
    }
    
    atomic_vector &operator= (const atomic_vector &Another)
    {
        _mutex.lock();
        Another._mutex.lock();
        atomic_vector tmp(Another);
        swap(*this, tmp);
        _mutex.unlock();
        Another._mutex.unlock();
        return *this;
    }
    
    // realsize = {0,1,2,4,7,...} size = {0,1,2,3,4,..}
    void push_back(T data)
    {
        _mutex.lock();
        if(array_size == 0)
        {
            T *result = new T[1];
            result[0] = data;
            delete[] array;
            array = result;
            array_size++;
            realsize++;
        }
        else
        {
            array_size++;
            if(array_size > realsize)
            {
                realsize *= 3;
                realsize /= 2;
                realsize += 1;
                T *result = new T[realsize];
                for(int i = 0; i < array_size - 1; i++)
                {
                    result[i] =  array[i];
                }
                result[array_size - 1] = data;/*
                for(int i = array_size; i < realsize; i++)
                {
                    result[i] = T();
                }*/
                delete[]array;
                array = result;
            }
            else
            {
                array_size++;
                array[array_size - 1] = data;
            }
        }
        _mutex.unlock();
    }
    
    T pop()
    {
        _mutex.lock();
        T _return = *(array + array_size - 1);
        if(array_size >= 1)
            array_size--;
        _mutex.unlock();
        return _return;
    }
    /*
    friend std::ostream & operator<< (std::ostream &stream , atomic_vector <T> &vector)
    {
        vector._mutex.lock();
        for (int i = 0; i < vector._size(); i++) {
            stream << vector.array[i];
        }
        vector._mutex.unlock();
        return stream;
    }*/
};

#endif /* atomic_vector_hpp */
