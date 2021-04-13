#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int ch[10001];
int arr[] = { -1,1,5 };

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	queue<int> q;
	int N, K, cnt = 0, i = 0;
	cin >> N >> K;
	// n개의 왕자. k번때에 빠져나온다.
	int x;
	for (int i = 1; i <= N; ++i)
		q.push(i);

	while (q.size() != 1)
	{
		++cnt;
		if (cnt == K)
		{
			q.pop();
			cnt = 0;
		}
		else // 빼고 다시 뒤로 집어넣는다. 
		{
			x = q.front();
			q.pop();
			q.push(x);
			
		}
	}
	cout << q.front();

	return 0;
}
