#include <iostream>
#include <string>
#include <algorithm>
#include <mutex>
#include <thread>
#include <pthread.h>
#include <vector>
using namespace std;
 
#define N 8
#define n 10 // Count of threads we have
 
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
    if (num_th > 0)
    {
	bool 2or3 = true;
	if(num_th >= (N - 2) / 2)
	{
		
	}
        if (first < last)
        {
            num_th = 0;
            int stairs = (last + 1) / n;
	    vector <int> Edges;
            vector <thread> Threads;
            for (int i = 0; i < stairs; i++)
            {
                if ((i + 1) * stairs - 1 < last){
		    Edges.push_back(i * stairs);
		    Edges.push_back((i + 1) * stairs - 1);
                    Threads.push_back( thread(MergeSort, Arr, i * stairs, (i + 1) * stairs - 1) );
                }
            }
 
            if ((last + 1) % n != 0)
                Threads.push_back(thread(MergeSort, Arr, (stairs - 1) * stairs, last));
 
            if ((last + 1) % n == 0)
            {
                for (int i = 0; i < stairs; i++)
                {
                    Threads[i].join();
                }
            }
            else
            {
                for (int i = 0; i < stairs + 1; i++)
                {
                    Threads[i].join();
                }
            }
	    //MergeSort(Arr, first, (first + last) / 2);
            //MergeSort(Arr, (first + last) / 2 + 1, last);	     
            //thread(Merge, Arr, first, last);
	    Merge(Arr, first, last);
        }
    }
    else{
        if (first < last)
        {
 
            MergeSort(Arr, first, (first + last) / 2);
            MergeSort(Arr, (first + last) / 2 + 1, last);
            Merge(Arr, first, last);
        }
    }
};

 
int main()
{ 
    int * mass = new int[N];
    for (int i = 0; i < N; i++){
        mass[i] = rand() % 20;
        cout << mass[i] << " ";
    }
    mass[0] = 17;
    mass[1] = 16;
    mass[2] = 15;
    mass[3] = 14;
    cout << '\n' << "We have massive from " << N << " elements and " << n << " threads" << '\n';
   
    MergeSort(mass, 0, N - 1);
 
    for (int i = 0; i < N; i++)
        cout << mass[i] << " ";

    cout << '\n';
    //system("pause>>void");	
    return 0;
}
