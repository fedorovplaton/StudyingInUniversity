#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class graph{
vector<vector<int>> G;
int Ways[100][100]; // 0 - no way; 1-  way was not visited; -1 - way was not visited
int n, m;
bool visited[100];
int CountOfWaysFromCurrentVertex[100];
public:
	graph(int _sizeN):n(_sizeN)
	{
		G.resize(_sizeN);
		for(int i = 0; i < _sizeN; i++)
			visited[i] = false;
		for(int i = 0; i < _sizeN; i++)
			for(int j = 0; j < _sizeN; j++)
				Ways[i][j] = 0;
	}
	void Add_Way(int a, int b)
	{
		CountOfWaysFromCurrentVertex[b] += 1;
		CountOfWaysFromCurrentVertex[a] += 1;
		Ways[a][b] = 1;
		Ways[b][a] = 1;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void DFS_MULTI_THREAD(int start_vertex)
	{
		visited[start_vertex] = true;
		if(CountOfWaysFromCurrentVertex[start_vertex] == 1)
		{
			for(int i  = 0; i < G[start_vertex].size(); i++)
			{
				if(Ways[start_vertex][G[start_vertex][i]] == 1)
				{
					Ways[start_vertex][G[start_vertex][i]] == -1;
					Ways[G[start_vertex][i]][start_vertex] == -1;
					CountOfWaysFromCurrentVertex[start_vertex] -= 1;
					CountOfWaysFromCurrentVertex[G[start_vertex][i]] -= 1;
					if(visited[G[start_vertex][i]] = false){
						visited[G[start_vertex][i]] = true;
						DFS_MULTI_THREAD(G[start_vertex][i]);
					}
				}
			}
		}
		if(CountOfWaysFromCurrentVertex[start_vertex] > 1)
		{

		}
	}
};


int main()
{
	graph G(12);
	G.Add_Way(1,2);
	G.Add_Way(2,3);
	G.Add_Way(3,4);
	G.Add_Way(4,6);
	G.Add_Way(6,11);
	G.Add_Way(11,12);
	G.Add_Way(2,5);
	G.Add_Way(5,8);
	G.Add_Way(8,9);
	G.Add_Way(8,10);
	G.Add_Way(9,11);
	G.Add_Way(10,11);
	G.Add_Way(3,7);
	G.Add_Way(5,4);
	G.Add_Way(4,7);
	G.Add_Way(7,9);
	return EXIT_SUCCESS;
}