#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt = 0;
vector<int> v;
// 왼쪽출력. 오른쪽은 안출력. 
void DFS(int level, int sum)
{
	if (level > N - 1)
	{
		if (sum == M)
			++cnt;
	}
	else
	{

		DFS(level + 1, sum + v[level]);
		DFS(level + 1, sum);
		DFS(level + 1, sum - v[level]);
	}
}

int main()
{
	cin >> N >> M;
	int i, a;
	for (i = 0; i < N; ++i)
	{
		cin >> a;
		v.push_back(a);
	}
	DFS(0, 0);
	cout << cnt;
	return 0;
}
