//
//  main.cpp
//  hw5 MergeSortMultiThread
//
//  Created by Platon on 18.12.17.
//  Copyright © 2017 Platon. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <mutex>
#include <thread>
#include <pthread.h>
#include <vector>
using namespace std;

#define N 10
#define n 6 // Count of threads we have

int num_th = n;
mutex array_changes;

void Merge(int *Arr, int first, int last)
{
    int middle, j;
    int *mas = new int[last + 1];
    middle = (first + last) / 2;
    int next_one_1 = first;
    int next_one_2 = middle + 1;
    for (j = first; j <= last; j++)
        if ((next_one_1 <= middle) && ((next_one_2>last) || (Arr[next_one_2] > Arr[next_one_1])))
        {
            mas[j] = Arr[next_one_1];
            next_one_1++;
        }
        else
        {
            mas[j] = Arr[next_one_2];
            next_one_2++;
        }
    array_changes.lock();
    for (j = first; j <= last; j++)
    {
        Arr[j] = mas[j];
    }
    array_changes.unlock();
    delete[]mas;
};

void MergeSort(int *Arr, int first, int last)
{
    //thread::id this_id = this_thread::get_id();
    //cout << this_id << " - id" << '\n';
    if(last - first == 1)
        Merge(Arr, first, last);
    else{
        if (first < last)
        {
            
            MergeSort(Arr, first, (first + last) / 2);
            MergeSort(Arr, (first + last) / 2 + 1, last);
            Merge(Arr, first, last);
        }
    }
};

int pow(int a, int deg)
{
    int c = deg;
    int m  = deg;
    for(int i = 2; i <= deg; i++)
        c *= m;
    return c;
    
}

void ThreadMergeSort(int *Arr, int first, int last)
{
    if(n == 1 || n == 0)
    {
        MergeSort(Arr, first, last); // if threads are not useful (If there are no additional threads)!
    }
    else{ // else
        int _M = n; // Count of threads
        int _N = N; // Count of elements in array
        int NM = _N / 2; // Check overcount of threads
        vector <int> Edges;
        if(_M >= NM)
        {//Good
            vector <thread> Threads;
            for(int i = 0; i < NM; i++)
            {
                Edges.push_back(i * 2);
                Edges.push_back(i * 2 + 1);
                Threads.push_back(thread(MergeSort, Arr, i * 2, i * 2 + 1));
                Threads[i].detach(); // Edited
            }/*
            for(int i = 0; i < NM; i++)
            {
                Threads[i].join();
            }*/
        }
        else
        {//Bad
            if(_N % _M == 0) // So, break array on _M threads and sort it separately
            {
                NM = _N / _M;
                vector <thread> Threads;
                for(int i = 0; i < _M; i++)
                {
                    Edges.push_back(i * NM);
                    Edges.push_back((i + 1) * NM - 1);
                    Threads.push_back(thread(MergeSort, Arr, i * NM, (i + 1) * NM - 1));
                    Threads[i].detach();
                }/*
                for(int i = 0; i < _M; i++)
                {
                    Threads[i].join();
                }*/
            }
            else{
                NM = _N / _M;
                vector <thread> Threads;
                for(int i = 0;  i < _M - 1; i++)
                {
                    Edges.push_back(i * NM);
                    Edges.push_back((i + 1) * NM - 1);
                    Threads.push_back(thread(MergeSort, Arr, i * NM, (i + 1) * NM - 1));
                    Threads[i].detach();
                }
                int dif = N - (_M - 1) * NM;
                Edges.push_back(_N - dif);
                Edges.push_back(last);
                Threads.push_back(thread(MergeSort, Arr, _N - dif, last));
                Threads[Threads.size()-1].detach();
            }
        }
        this_thread::sleep_for(2s);
        // Start Merging
        /*
        vector <thread> MThreads;
        int year = 2;
        int j = 0;
        bool finish = false;
        vector <int> EdgeCurrent;
        bool current = true;
        while( !finish ){
            if(Edges.size() == 2 || EdgeCurrent.size() == 2){
                Merge(Arr, first, last);
                break;
            }
            
            if(current){
                int k = 0;
                if(Edges.size() % 4 != 0 && (Edges.size() / 4) % 2 != 0){
                    for(int i = 0; i < Edges.size() / 4 - 1; i++){
                        MThreads.push_back(thread(Merge, Arr, i * 4, (i + 1) * 4 - 1));
                        //Merge(Arr, i * 4, (i + 1) * 4 - 1);
                        EdgeCurrent.push_back(i * 4);
                        EdgeCurrent.push_back( (i + 1) * 4 - 1);
                        k++;
                    }
                    EdgeCurrent.push_back(k * 4);
                    EdgeCurrent.push_back(last);
                    
                }
                else{
                    for(int i = 0; i < Edges.size() / 4; i++){
                        MThreads.push_back(thread(Merge, Arr, i * 4, (i + 1) * 4 - 1));
                        //Merge(Arr, i * 4, (i + 1) * 4 - 1);
                        EdgeCurrent.push_back(i * 4);
                        EdgeCurrent.push_back( (i + 1) * 4 - 1);
                    }
                }
                for(int i = 0; i < MThreads.size(); i++)
                    MThreads[i].join();
                MThreads.resize(0);
                Edges.resize(0);
                current = false;
            }
            else{
                int k = 0;
                if(EdgeCurrent.size() % 4 != 0 && (EdgeCurrent.size() / 4) % 2 != 0){
                    for(int i = 0; i < EdgeCurrent.size() / 4 - 1; i++){
                        MThreads.push_back(thread(Merge, Arr, i * 4, (i + 1) * 4 - 1));
                        //Merge(Arr, i * 4, (i + 1) * 4 - 1);
                        Edges.push_back(i * 4);
                        Edges.push_back( (i + 1) * 4 - 1);
                        k++;
                    }
                    Edges.push_back(k * 4);
                    Edges.push_back(last);
                    
                }
                else{
                    for(int i = 0; i < EdgeCurrent.size() / 4; i++){
                        MThreads.push_back(thread(Merge, Arr, i * 4, (i + 1) * 4 - 1));
                        //Merge(Arr, i * 4, (i + 1) * 4 - 1);
                        Edges.push_back(i * 4);
                        Edges.push_back( (i + 1) * 4 - 1);
                    }
                }
                for(int i = 0; i < MThreads.size(); i++)
                    MThreads[i].join();
                MThreads.resize(0);
                EdgeCurrent.resize(0);
                current = true;
            }
        }*/
        vector <thread> Threads2;
        int j = 4;
        while(1){
            if(Edges.size() > j){
                int g = Edges.size() / j;
                if(g > 1){
                    for(int i = 0; i < g; i++){
                        Threads2.push_back(thread( Merge, Arr, Edges[j*i], Edges[i * j + j - 1]));
                        Threads2.back().join();
                    }
                }
                else{
                    Merge(Arr, first, last);
                    break;
                }
            }
            j *= 2;
        }
    }
    
}


int main()
{
    int * mass = new int[N];
    for (int i = 0; i < N; i++){
        mass[i] = rand() % 20;
    }
    mass[0] = 100;
    mass[1] = 99;
    for (int i = 0; i < N; i++){
        cout << mass[i] << " ";
    }
    cout << '\n' << "We have massive from " << N << " elements and " << n << " threads" << '\n';
    
    ThreadMergeSort(mass, 0, N - 1);
    
    for (int i = 0; i < N; i++)
        cout << mass[i] << " ";
    
    cout << '\n';
    //system("pause>>void");
    return 0;
}
