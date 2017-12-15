//
//  main.cpp
//  Multi-threading DFS
//
//  Created by Platon on 09.12.17.
//  Copyright © 2017 Platon. All rights reserved.
//

#include <thread>
#include <iostream>
#include <vector>
#include <ctime>
#include <mutex>
using namespace std;


#define N 14
vector <vector<int>> g(N);
mutex used_mutex;
bool used[N];


//-----------------------------------
//                7-8               |
//               /   \              |
// start->[0] - 1 --- 9 ---         |
//           \   \  /       \       |
//            2   5 - 10 -- 11 - 13 |
//           / \     / \            |
//          3   4 - 6   12          |
//-----------------------------------

void dfs_mt(int current_vertex_number) // DFS WITH USING THREADS
{
    used_mutex.lock();
    used[current_vertex_number] = true;
    used_mutex.unlock();
    for(int i = 0; i < g[current_vertex_number].size(); i++)
    {
        if(!used[g[current_vertex_number][i]]){
            thread new_root(dfs_mt, g[current_vertex_number][i]);
            new_root.detach();
        }
    }
}

void dfs_st(int current_vertex_number) // STANDART DFS WITHOUT USING THREADS
{
    used[current_vertex_number] = true;
    for(int i = 0; i < g[current_vertex_number].size(); i++)
    {
        if(!used[g[current_vertex_number][i]]){
            dfs_st(g[current_vertex_number][i]);
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    g[0].push_back(1);
    g[0].push_back(2);
    g[2].push_back(3);
    g[2].push_back(0);
    g[2].push_back(4);
    g[1].push_back(7);
    g[1].push_back(5);
    g[1].push_back(0);
    g[1].push_back(9);
    g[3].push_back(2);
    g[4].push_back(3);
    g[4].push_back(6);
    g[5].push_back(1);
    g[5].push_back(9);
    g[5].push_back(10);
    g[6].push_back(4);
    g[6].push_back(10);
    g[7].push_back(1);
    g[7].push_back(8);
    g[8].push_back(7);
    g[8].push_back(9);
    g[9].push_back(1);
    g[9].push_back(5);
    g[9].push_back(8);
    g[9].push_back(11);
    g[10].push_back(5);
    g[10].push_back(6);
    g[10].push_back(11);
    g[10].push_back(12);
    g[11].push_back(9);
    g[11].push_back(10);
    g[11].push_back(13);
    g[12].push_back(10);
    g[13].push_back(11);
    for(int i = 0; i < N; i++){
        used[i] = false;
    }
    
    cout << "Time Checker for multi-thread-dfs: " << '\n';
    unsigned int start_time =  clock();
    dfs_mt(0);
    unsigned int end_time =  clock();
    cout << start_time << " - start time" << '\n' << end_time << " - end time"<<'\n'<<end_time-start_time  << " - final working time"<< '\n';
    //------check_standart_dfs-----------
    for(int i = 0; i < N; i++){
        used[i] = false;
    }
    cout << "Time Checker for one-thread-dfs: " << '\n';
    unsigned int start_time2 =  clock();
    dfs_st(0);
    unsigned int end_time2 =  clock();
    cout << start_time2 << " - start time" << '\n' <<end_time2<< " - end time"<<'\n'<<end_time2-start_time2 << " - final working time"<< '\n';
    //-----------------------------------
    
    return 0;
}
