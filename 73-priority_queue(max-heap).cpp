#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int a;
	priority_queue<int> pQ; // 우선순위 큐의 디폴트는 최대힙 
	while(true)
	{
		cin >> a;
		if (a == -1) break;
		else if (a == 0)
		{
			if(pQ.empty()){
				cout << -1;
			}
			else
			{
				cout << pQ.top() << endl; // top은 루트값.
				pQ.pop(); 
			}
		}
		else pQ.push(a);
	}
	
	return 0;
}
