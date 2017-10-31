#include<iostream>
using namespace std;

void ShellSort(int *arr,int len)
{
	int i, j, temp = 0, gap = len;

	do {
		gap = gap / 3 + 1;
		for (i = gap; i < len; i++)
		{
			temp = arr[i];
			if (arr[i] < arr[i - gap])
			{
				for (j = i - gap; arr[j] > temp; j-=gap)
				{
					arr[j + gap] = arr[j];
				}
				arr[j + gap] = temp;
			}
		}
	} while (gap > 1);
}

void ShellSort1(int *arr,int d,int len)
{
	int i, j, temp = 0;
	for (i = d; i < len; i++)
	{
		temp = arr[i];
		j = i - d;
		while (j>=0&&temp<arr[j])
		{
			arr[j + d] = arr[j];
			j-=d;
		}

		arr[j + d] = temp;
	}
}

int main(void)
{
	int arr[10] = { 4,2,7,1,8,9,0,3,6,5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int d = len / 2;

	while (d >= 1) {

		ShellSort(arr, len);
		d /= 2;
	}

	//	ShellSort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}