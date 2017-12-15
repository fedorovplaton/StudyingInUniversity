#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
 
using namespace std;

int main()
{
    queue<int> produced_nums;
    mutex m;
    condition_variable cond_var;
    bool done = false;
    bool notified = false;
 
    thread producer([&]() {
        for (int i = 0; i < 5; ++i) {
            this_thread::sleep_for(chrono::seconds(1));
            unique_lock<mutex> lock(m);
            cout << "producing " << i << '\n';
            produced_nums.push(i);
            notified = true;
            cond_var.notify_one();
        }
 
        done = true;
        cond_var.notify_one();
    });
 
   thread consumer([&]() {
        unique_lock<mutex> lock(m);
        while (!done) {
            while (!notified) {  // loop to avoid spurious wakeups
                cond_var.wait(lock);
            }
            while (!produced_nums.empty()) {
                cout << "consuming " << produced_nums.front() << '\n';
                produced_nums.pop();
            }
            notified = false;
        }
    });
 
    producer.join();
    consumer.join();
}