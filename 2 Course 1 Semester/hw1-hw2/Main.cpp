#include <iostream>
#include <thread>

using namespace std;

#define N 3

void Input(int** M)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> M[i][j];
		}
	}
	return;
}

void Output(int **M)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << '\n';
	}
}

void SortLowToHigh(int* cm)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			if(cm[i] > cm[j])
			{
				int c = cm[i];
				cm[i] = cm[j];
				cm[j] = c;
			}
		}
	}
	return;
}

void SortByLineNumber(int ** M, int number)
{
	int* cm = new int[N];
	for(int i = 0; i < N; i++)
	{
		cm[i] = M[number][i];
	}
	SortLowToHigh(cm);
	for(int i = 0; i < N; i++)
	{
		M[number][i] = cm[i];
	}
	delete(cm);
	return;
}

void MainFunction(int** M)
{
	thread* Threads[N];
	for(int i = 0; i < N; i ++)
	{
		Threads[i] = new thread(SortByLineNumber, M, i);
		Threads[i]->join();
	}
}

int main()
{
	//----Array Generation----
	int** a = new int*[N];
	for(int i = 0; i < N; i++)
		a[i] = new int[N];
	//----Array.Input----
	Input(a);
	//----Array.Sort----
	MainFunction(a);
	//----Array.Output----
	Output(a);
    //----System Commands----
	system("pause");
	return EXIT_SUCCESS;
}

