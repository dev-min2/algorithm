#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v[21];
int ch[21];
int visitedCount[21];
void BFS(int vertex)
{
	int i, cnt;
	queue<int> q;
	q.push(vertex);
	ch[vertex] = 1;
	while (true)
	{
		cnt = 0;
		if (q.empty()) break;
		int x = q.front();
		q.pop();
		
		for (i = 0; i < v[x].size(); ++i)
		{
			if (ch[v[x][i]] == 0)
			{
				q.push(v[x][i]);
				ch[v[x][i]] = 1; // 방문.
				visitedCount[v[x][i]] = visitedCount[x] + 1;
				// 나를 한번만에 방문한 정점의 visitedCount + 1. 즉 1->4번 1번만에 왔고. 4->5. 1번만에 왔다. 이것을 1->4->5로 하면 4번정점은 1번정점에서 1번만에 오고.
				// 5번정점은 4번정점을 통해 1번만에 왔으니. visitedCount[4] + 1한값이 5번정점의 최소 간선수.
			}
			
		}
	}
}

int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; ++i) 
	{
		cin >> a >> b;
		v[a].push_back(b);
	} // 인접리스트 방식 
	BFS(1);

	for (a = 2; a <= N; ++a)
	{
		cout << a << " : " << visitedCount[a] << "\n";
	}

	return 0;
}
