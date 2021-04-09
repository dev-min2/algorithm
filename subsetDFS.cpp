#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ch[11];
// 왼쪽출력. 오른쪽은 안출력. 
void DFS(int level)
{
	if (level > N)
	{
		int i;
		for(i = 0; i <= N; ++i)
		{
			if(ch[i] == 1)
				cout << i << " ";
		}
		cout << "\n";
	}
	else
	{
		ch[level] = 1;
		DFS(level + 1);
		ch[level] = 0;
		DFS(level + 1);
	}
}

int main()
{
	cin >> N;
	
	DFS(1);
	
	return 0;
}