#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int a;
	priority_queue<int> pQ; // �켱���� ť�� ����Ʈ�� �ִ��� 
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
				cout << pQ.top() << endl; // top�� ��Ʈ��.
				pQ.pop(); 
			}
		}
		else pQ.push(a);
	}
	
	return 0;
}
