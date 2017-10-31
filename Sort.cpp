#include<iostream>
using namespace std;

#define MAXSIZE 20

typedef struct
{
	int key;  // Ҫ�ȽϵĹؼ��� 
}Record;

// ֱ�Ӳ�������

void InsertSort(Record *r,int len)
{
	int i, j;
	Record temp;				 //  ������ 
	for (i=1;i<len;i++)
	{
		temp= r[i];
		j = i - 1;
		while (j>=0&&temp.key<r[j].key)
		{
			r[j + 1] = r[j];
			j--;
		}
		r[j + 1] = temp;
	}
}

// �۰��������

void BinSort(Record *arr, int len)
{
	int i, j;
	Record temp;
	int low =0,high=0,mid=0;
	
	for (i=1;i<len;i++)
	{
		temp = arr[i];   // ������
		low = 0;
		high = i;
	
		while (low<=high)     // �ҵ��ȵ�ǰҪ�������ֵ��С����ֵ��λ��
		{
			mid = (low + high) / 2;
			if (temp.key < arr[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}

		for (j = i-1; j >=low; j--)   // ��¼���������
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

// ð������

void BubbleSort(Record *arr,int len)
{
	bool change = true;

	for (int i=0;i<len-1&&change;i++)
	{
		for (int j=0;j<len-i-1;j++)
		{
			change = false;
			if (arr[j].key>arr[j+1].key)
			{
				Record temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				change = true;
			}
		}
	}
}

// ϣ������

void ShellSort(Record *arr,int d,int len)
{
	int i, j;
	Record temp;
	for (i =d; i < len; i++)
	{
		temp = arr[i];    //������
		j = i - d;
		while (j>=0&&temp.key<arr[j].key)
		{
			arr[j + d] = arr[j];
			j-=d;
		}
		arr[j + d] = temp;
	}
}

// ��ѡ������

void SelectSort(Record *arr,int len)
{
	int i, j;
	int k = 0;;
	for (i=0;i<len-1;i++)		// ��������
	{
		k = i;					// ѡȡ��Сֵ����¼���±�
		for (j=i+1;j<len;j++)
		{
			if (arr[j].key<arr[k].key)
			{
				k = j;
			}
		}
		if (i!=k)
		{
			Record temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

// һ�˿���������㷨

int QKpass(Record *arr,int low,int high)
{
	Record key = arr[low];				//	ѡ���¼�Ĺؼ���

	while (low<high)
	{
		while (low < high&&arr[high].key>=key.key)     // high ���ҵ�����С����key.key��Ԫ��
			high--;
		if (low < high)
		{
			arr[low] = arr[high];
			low++;
		}
		while (low < high&&arr[high].key<key.key)           // low�������Ҵ���key.key��Ԫ��
			low++;
		if (low < high)
		{
			arr[high] = arr[low];
			high--;
		}

		arr[low] = key;									    // ����׼��¼���浽low=high��λ��
	}
	return low;											    // ���ػ�׼��¼λ��
}

// ��������

void QuickSort(Record *arr, int low, int high)
{
	int pos;
	if (low <high)
	{
		pos = QKpass(arr, low, high);             // ����һ�ɿ���������֧��Ϊ�绮��Ϊ�����ӱ�
		QuickSort(arr, low, pos-1);				// �����ӱ���п�������
		QuickSort(arr, pos+1, high);				// �����ӱ���п�������
	}
}

// ������arr[low,mid]��arr[mid+1,high]�ϲ�

void Merge(Record* arr, int low,int  mid,int  high,Record* temp)
{
	int i, j, k;
	i = low;
	j = mid + 1;     // �����ظ��Ƚ�arr[mid]
	k = low;

	while (i <=mid&&j<=high)     // ����arr[low,mid]������arr[mid+1,high]��û�кϲ���temp��ȥ
	{
		if (arr[i].key<arr[j].key)       // ���arr[i].key<arr[j].key��ֵ
			temp[k] = arr[i++];
		else
			temp[k]=arr[j++];
		k++;
	}
	
	while (i<=mid)				 // ��arr[low,mid]��ʣ���Ԫ�أ�������temp������
	{
		temp[k++] = arr[i++];
	}
	while (j<=high)				// ��arr[mid+1,high]��ʣ���Ԫ�أ�����������temp��
	{
		temp[k++] = arr[j++];
	}
}

// �鲢����

void MSort(Record *arr, int low, int high, Record *temp)
{

	Record t[MAXSIZE];							//	��������
	//int mid;
	if (low == high)
	{
		temp[low] = arr[low];
	}
	else
	{
		int mid = (low + high) / 2;
		MSort(arr,low,mid,t);    // �������
		MSort(arr,mid+1,high,t); // �ұ�����
		Merge(t,low,mid,high,temp);
	}

}

void MergeSort(Record *arr,int len)
{
	MSort(arr,0,len,arr);
}

// �ؽ���

void sift(Record *arr,int start,int end)
{
	int i, j;
	i = start;
	j = 2 * i;
	Record temp = arr[i];
	bool finish = false;	
	while (j <= end && ! finish )
	{
		if (j < end&&arr[j].key < arr[j + 1].key)	  // �ҵ����������нϴ��һ���ڵ�		
			j = j + 1;

		if (arr[j].key > temp.key)					 // �����ǰ�ڵ��ֵ���ڸ��ڵ��ֵ���ѵ�ǰ�ڵ��ֵ���Ƹ����ڵ�,��������ǰ�ڵ���������ϱ���
		{
			arr[i] = arr[j];
			i = j;
			j = 2 * i;
		}
		else
			finish = true;
	}
	arr[i] = temp;
}

// ������

void HeapSort(Record *arr,int len)				//	 ��arr[1...n]���ж��ţ�ִ�б��㷨��r�м�¼���ؼ�����С������������
{
	int i;
	for (i=len/2;i>=0;i--)						// ������
	{
		sift(arr,i,len);
	}

	for (i=len-1;i>=0;i--)
	{
		Record temp = arr[0];					// ���Ѷ���¼��������һ����¼���н���
		arr[0] = arr[i];
		arr[i] = temp;
		sift(arr,0,i-1);						// ����¼��������һ����¼���н������ؽ���
	}
}

int main(void)
{
	// 99 , 58 , 230 , 100 , 75 , 69 , 200 , 180 , 66 , 18 ,135
	Record arr1[] = { 0,8, 9 ,5 ,6,7, 3 ,4, 2,1,0};
	Record arr[] = {99 , 58 , 230 , 100 , 75 , 69 , 200 , 180 , 66 , 18 ,135 };
	int len = sizeof(arr) / sizeof(arr[0]);
//	InsertSort(arr,len);
//	BinSort(arr,len);
//	BubbleSort(arr,len);
	//int d = len / 2;
	//while (d>=1)
	//{
	//	ShellSort(arr,d,len);
	//	d = d / 2;
	//}

//	QuickSort(arr,0,len-1);

//	MergeSort(arr,len-1);
	
//	HeapSort(arr,len);

	SelectSort(arr,len);
	for (int i = 0; i < len; i++)
		cout << arr[i].key << "  ";
	cout << endl;

	return 0;
}