#include<iostream>
using namespace std;

void insert_sort(int *arr,int len)
{
	int i, j, temp = 0;
	for (i = 1; i < len; i++)     // 表示要插入的次数为len-1次
	{
		temp = arr[i];      // 把带排元素赋值给temp,temp在在wile循环中并不改变，这样比较方便并且它是带插入的元素
		j = i - 1;    // 用j来记住当进行前元素的前一个元素的位置

		while (j>=0&&temp<arr[j])    // 将比当前元素大的元素都往后移一个位置 
		{
			arr[j + 1] = arr[j];     //顺序比较和移动，依次将元素向后移动一个位置
			j--;
		}
		arr[j + 1] = temp;    // 元素移后要插入的位置就空了，找到该位置插入.
	}
}

void InsertSort(int *arr,int len)
{
	int i, j, temp = 0;
	for (i=1;i<len;i++)
	{
		temp = arr[i];
		if (arr[i]<arr[i-1])
		{
			for (j = i - 1; arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

int main(void)
{
	int arr[10] = { 4,2,7,1,8,9,0,3,6,5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	insert_sort(arr,len);
//	InsertSort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}