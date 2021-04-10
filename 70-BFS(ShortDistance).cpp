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
				ch[v[x][i]] = 1; // �湮.
				visitedCount[v[x][i]] = visitedCount[x] + 1;
				// ���� �ѹ����� �湮�� ������ visitedCount + 1. �� 1->4�� 1������ �԰�. 4->5. 1������ �Դ�. �̰��� 1->4->5�� �ϸ� 4�������� 1���������� 1������ ����.
				// 5�������� 4�������� ���� 1������ ������. visitedCount[4] + 1�Ѱ��� 5�������� �ּ� ������.
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
	} // ��������Ʈ ��� 
	BFS(1);

	for (a = 2; a <= N; ++a)
	{
		cout << a << " : " << visitedCount[a] << "\n";
	}

	return 0;
}
