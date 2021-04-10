#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int ch[10001];
int arr[] = {-1,1,5};

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	int s,e, x,pos,i; // pos는 이동할 변수
	queue<int> q;
	cin >> s >> e;
	ch[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		// 5를 꺼낸다.
		for(i = 0; i < 3; ++i)
		{
			pos = x + arr[i];
			if (pos <= 0 || pos > 10000) continue; // 좌표를 벗어날경우 무시. 
			if (pos == e)
			{
				cout << ch[x]; // ch[pos]가 아닌 이유는 처음에 ch[s]=1을 했으므로 +1이 이미 더해진 상태이기때문.
							   // 즉. -1인 지점 레벨 위의 단계에서 바로 밑의 단계가 찾는경우이니 그냥 -1했다고 보면된다. 
				return 0; // 프로그램종료 
			}
			if(ch[pos]==0){
				ch[pos] = ch[x] + 1;
				q.push(pos);
			}
				
		} 
	}

	return 0;
}
