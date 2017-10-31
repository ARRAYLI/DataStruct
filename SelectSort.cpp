/*
#include<iostream>
using namespace std;

// 直接选择排序
void SelectSort(int *arr,int len)
{
	int i, j, min, temp;
	int count1 = 0, count2 = 0;
	for (i = 0; i < len-1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			count1++;
			if (arr[j]<arr[min])
			{
				count2++;
				min = j;
			}
		}
		if (min!=i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}

	}
	cout << "总共进行了" << count1 << "次比较，共进行了" << count2 << "次移动" << endl;
}

int main(void)
{
	int arr[10] = { 4,2,7,1,8,9,0,3,6,5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	SelectSort(arr,len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}

*/


// ===============================排序复习=================================

#include<iostream>
#include<algorithm>
using namespace std;

void BubleSort(int *arr,int len)
{
	int i, j;
	for (i=0;i<len-1;i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void BubleSort1(int *arr,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}
	}
}

void BubleSort2(int *arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j =len-1;j>i ; j--)
		{
			if (arr[j-1] > arr[j])
			{
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;

			}
		}
	}
}

void BubleSort3(int *arr, int len)
{
	bool flag = true;
	for (int i = 0; i < len - 1&&flag; i++)
	{
		for (int j = len - 1; j>i; j--)
		{
			flag = false;
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
	}
}

void BubleSort4(int *arr, int len)
{
	sort(arr,arr+len);
}

void InsertSort(int *arr, int len)
{
	int i, j, temp = 0;

	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void InsertSort1(int *arr, int len)
{
	int i, j, temp = 0;

	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		//		j = i - 1;
		if (arr[i] < arr[i - 1])
		{
			for (j = i - 1; arr[j]>temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

void SelectSort(int *arr, int len)
{
	int i, j, min = 0;
	for (i = 0; i < len-1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j]<arr[min])
			{
				min = j;
			}

		}

		if (min!=i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;

		}
	}
}



int main(void)
{
	int arr[10] = { 2,9,6,8,4,7,3,1,0 ,5};
	int len = sizeof(arr) / sizeof(arr[0]);

//	BubleSort(arr,len);
//	BubleSort2(arr, len);
//	BubleSort3(arr, len);
//	BubleSort4(arr, len);

//	InsertSort(arr,len);
	
//	InsertSort1(arr, len);
	SelectSort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}