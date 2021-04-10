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
	int s,e, x,pos,i; // pos�� �̵��� ����
	queue<int> q;
	cin >> s >> e;
	ch[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		// 5�� ������.
		for(i = 0; i < 3; ++i)
		{
			pos = x + arr[i];
			if (pos <= 0 || pos > 10000) continue; // ��ǥ�� ������ ����. 
			if (pos == e)
			{
				cout << ch[x]; // ch[pos]�� �ƴ� ������ ó���� ch[s]=1�� �����Ƿ� +1�� �̹� ������ �����̱⶧��.
							   // ��. -1�� ���� ���� ���� �ܰ迡�� �ٷ� ���� �ܰ谡 ã�°���̴� �׳� -1�ߴٰ� ����ȴ�. 
				return 0; // ���α׷����� 
			}
			if(ch[pos]==0){
				ch[pos] = ch[x] + 1;
				q.push(pos);
			}
				
		} 
	}

	return 0;
}
