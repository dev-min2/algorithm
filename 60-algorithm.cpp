#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int ch[11], sum = 0,total = 0;
bool flag = false;
// 왼쪽출력. 오른쪽은 안출력. 
void DFS(int level)
{
	if (level > N)
	{
		if(sum == (total - sum))
		{
			flag = true;
		}
	}
	else
	{
		sum += v[level];
		DFS(level + 1);
		sum -= v[level];
		DFS(level + 1);
	}
}

int main()
{
	cin >> N;
	int i,a;
	for(i = 0; i < N; ++i){
		cin >> a;
		v.push_back(a);
		total += a;
	}
	DFS(1);
	
	if(flag)
		cout << "YES";
	else cout << "NO";
	return 0;
}
