#include<iostream>
#include<algorithm>
using namespace std;

void BubleSort(int *arr,int len)
{
	int count1 = 0, count2 = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			count1++;
			if (arr[i] > arr[j])
			{
				count2++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "总共进行了" << count1 << "次比较，共进行了" << count2 << "次移动" << endl;
}

void BubleSort1(int *arr, int len)
{
	int count1 = 0, count2 = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = len-1;j>i; j--)
		{
			count1++;
			if (arr[j-1] > arr[j])
			{
				count2++;
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "总共进行了" << count1 << "次比较，共进行了" << count2 << "次移动" << endl;
}

void BubleSort3(int arr[], int len)
{
	int count1 = 0, count2 = 0;
	bool flag = true;
	for (int i = 0; i < len - 1&&flag; i++)
	{
		for (int j = len - 1; j>i; j--)
		{
			count1++;
			flag = false;
			if (arr[j - 1] > arr[j])
			{
				count2++;
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
	}
	cout << "总共进行了" << count1 << "次比较，共进行了" << count2 << "次移动" << endl;
}

void BubleSort4(int *arr,int len)
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
	sort(arr,arr+len);
}

int main(void)
{
//	int arr[10] = { 3,8,5,9,0,1,7,6,4,2 };

	int arr[10] = { 1,0,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);

//	BubleSort(arr,len);
//	BubleSort1(arr, len);
//	BubleSort2(arr, len
//	BubleSort3(arr, len);

	BubleSort4(arr, len);

	int count1 = 0, count2 = 0;
	bool flag = true;
	for (int i = 0; i < len - 1&&flag; i++)
	{
		for (int j = len - 1; j>i; j--)
		{
			count1++;
			flag = false;
			if (arr[j - 1] > arr[j])
			{
				count2++;
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
	}
	cout << "总共进行了" << count1 << "次比较，共进行了" << count2 << "次移动" << endl;


	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}