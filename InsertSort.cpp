#include<iostream>
using namespace std;

void insert_sort(int *arr,int len)
{
	int i, j, temp = 0;
	for (i = 1; i < len; i++)     // ��ʾҪ����Ĵ���Ϊlen-1��
	{
		temp = arr[i];      // �Ѵ���Ԫ�ظ�ֵ��temp,temp����wileѭ���в����ı䣬�����ȽϷ��㲢�����Ǵ������Ԫ��
		j = i - 1;    // ��j����ס������ǰԪ�ص�ǰһ��Ԫ�ص�λ��

		while (j>=0&&temp<arr[j])    // ���ȵ�ǰԪ�ش��Ԫ�ض�������һ��λ�� 
		{
			arr[j + 1] = arr[j];     //˳��ȽϺ��ƶ������ν�Ԫ������ƶ�һ��λ��
			j--;
		}
		arr[j + 1] = temp;    // Ԫ���ƺ�Ҫ�����λ�þͿ��ˣ��ҵ���λ�ò���.
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