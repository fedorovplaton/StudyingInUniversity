#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

queue <int> d_queue;
std::condition_variable d_cond;
mutex mut;

void data_prep(){
	i = 0;
	while(i < 10){
		int tmp = prepare_data();
		mut.lock();
		d_queue.push(tmp);
		mut.unlock();
		d_cond.notify_one();
		i++;
	}
}

void void_pros(){
	while(true){
		d_cond.wait();
		mut.lock();
		int tmp = d_queue.front();
		d_queue.pop();
		mut.unlock();
		process(tmp);
		if(false)
		{
			break;
		}
	}
}

int main()
{
	
	cout << "Hello";

}
