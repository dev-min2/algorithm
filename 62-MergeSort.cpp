#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int sorted[101];

void Merge(int arr[], int lt, int rt)
{
	int mid;
	int p1,p2,p3;
	if(lt < rt) // ���Ұ� �ϳ��ΰ��� ����x 
	{
		mid = (lt + rt) / 2;
		Merge(arr,lt,mid);
		Merge(arr,mid + 1, rt); // ���Ұ���. 
		p1 = lt;
		p2 = mid + 1;
		p3 = lt;
		while(p1 <= mid && p2 <= rt)
		{
			if(arr[p1] > arr[p2]) sorted[p3++] = arr[p2++]; // ��������
			else sorted[p3++] = arr[p1++]; 
		}
		while(p2 <= rt) // p2�� ������� 
			sorted[p3++] = arr[p2++];
		while(p1 <= mid)
			sorted[p3++] = arr[p1++];
		
		// �����Ѱ����� �ٽ� �ű�� ����.
		for(int i = lt; i <= rt; ++i)
			arr[i] = sorted[i];	 
		
	}
}

int main()
{
	int arr[101] = {};
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> arr[i];
	
	Merge(arr, 0, N - 1);
	
	for(int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	return 0;
}
