#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<vector<int> > v(9, vector<int>(9, 0));
int ch[8][8];
// 출발좌표는 1,1 상우 하 좌 순으로 움직인다. 
int goY[] = { -1,0,1,0 }; // 위 오 밑 왼
int goX[] = { 0,1,0,-1 }; //  
void DFS(int y, int x)
{
	int i;
	if (x == 7 && y == 7)
	{
		++cnt;
	}
	else
	{
		for (i = 0; i < 4; ++i) // 상우하좌
		{
			if (ch[y + goY[i]][x + goX[i]] == 0 && v[y + goY[i]][x + goX[i]] == 0)
			{
				if (y + goY[i] < 1 || y + goY[i] > 7) continue;
				if (x + goX[i] < 1 || x + goX[i] > 7) continue;
				ch[y + goY[i]][x + goX[i]] = 1; // 방문한곳 체크.
				//cout << "y좌표 : " << y + goY[i] << " x 좌표 : " << x + goX[i] << endl;
				DFS(y + goY[i], x + goX[i]);
				ch[y + goY[i]][x + goX[i]] = 0;
			}
		}
	}
}

int main(void)
{
	int i, j;
	for (i = 1; i <= 7; ++i)
	{
		for (j = 1; j <= 7; ++j)
		{
			cin >> v[i][j];
		}
	}
	ch[1][1] = 1; // 처음 시작점(방문체크!) 
	DFS(1, 1);
	cout << cnt;
}