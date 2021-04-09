#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[8];
int ch[8];
void BFS(int vertex)
{
	int i;
	queue<int> q;
	q.push(vertex);
	ch[vertex] = 1;
	
	while(true)
	{
		if(q.empty()) break; // 큐가 비어있으면 탈출. 
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(i = 0; i < v[x].size(); ++i)
		{
			if(ch[v[x][i]] == 0)
			{
				q.push(v[x][i]); // 우선 다 담는다. 
				ch[v[x][i]] = 1;
			}
		}
	}
	
}

int main()
{
	int a,b;
	for(int i = 0; i < 6; ++i) // 간선 정보 6개.
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	} // 인접리스트 방식 
	BFS(1);
	
	return 0;
}
