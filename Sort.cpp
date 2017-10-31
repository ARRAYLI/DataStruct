#include<iostream>
using namespace std;

#define MAXSIZE 20

typedef struct
{
	int key;  // 要比较的关键字 
}Record;

// 直接插入排序

void InsertSort(Record *r,int len)
{
	int i, j;
	Record temp;				 //  监视哨 
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

// 折半插入排序

void BinSort(Record *arr, int len)
{
	int i, j;
	Record temp;
	int low =0,high=0,mid=0;
	
	for (i=1;i<len;i++)
	{
		temp = arr[i];   // 监视哨
		low = 0;
		high = i;
	
		while (low<=high)     // 找到比当前要插入的数值的小的数值的位置
		{
			mid = (low + high) / 2;
			if (temp.key < arr[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}

		for (j = i-1; j >=low; j--)   // 记录依次向后羿
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

// 冒泡排序

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

// 希尔排序

void ShellSort(Record *arr,int d,int len)
{
	int i, j;
	Record temp;
	for (i =d; i < len; i++)
	{
		temp = arr[i];    //监视哨
		j = i - d;
		while (j>=0&&temp.key<arr[j].key)
		{
			arr[j + d] = arr[j];
			j-=d;
		}
		arr[j + d] = temp;
	}
}

// 简单选择排序

void SelectSort(Record *arr,int len)
{
	int i, j;
	int k = 0;;
	for (i=0;i<len-1;i++)		// 控制躺数
	{
		k = i;					// 选取最小值，记录其下标
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

// 一趟快速排序的算法

int QKpass(Record *arr,int low,int high)
{
	Record key = arr[low];				//	选择记录的关键字

	while (low<high)
	{
		while (low < high&&arr[high].key>=key.key)     // high 从右到左找小等于key.key的元素
			high--;
		if (low < high)
		{
			arr[low] = arr[high];
			low++;
		}
		while (low < high&&arr[high].key<key.key)           // low从左到右找大于key.key的元素
			low++;
		if (low < high)
		{
			arr[high] = arr[low];
			high--;
		}

		arr[low] = key;									    // 将基准记录保存到low=high的位置
	}
	return low;											    // 返回基准记录位置
}

// 快速排序

void QuickSort(Record *arr, int low, int high)
{
	int pos;
	if (low <high)
	{
		pos = QKpass(arr, low, high);             // 调用一躺快速排序，以支点为界划分为两个子表
		QuickSort(arr, low, pos-1);				// 对左子表进行快速排序
		QuickSort(arr, pos+1, high);				// 对右子表进行快速排序
	}
}

// 将数组arr[low,mid]与arr[mid+1,high]合并

void Merge(Record* arr, int low,int  mid,int  high,Record* temp)
{
	int i, j, k;
	i = low;
	j = mid + 1;     // 避免重复比较arr[mid]
	k = low;

	while (i <=mid&&j<=high)     // 数组arr[low,mid]与数组arr[mid+1,high]均没有合并到temp中去
	{
		if (arr[i].key<arr[j].key)       // 如果arr[i].key<arr[j].key的值
			temp[k] = arr[i++];
		else
			temp[k]=arr[j++];
		k++;
	}
	
	while (i<=mid)				 // 把arr[low,mid]中剩余的元素，拷贝到temp数组中
	{
		temp[k++] = arr[i++];
	}
	while (j<=high)				// 把arr[mid+1,high]中剩余的元素，拷贝到数组temp中
	{
		temp[k++] = arr[j++];
	}
}

// 归并排序

void MSort(Record *arr, int low, int high, Record *temp)
{

	Record t[MAXSIZE];							//	辅助数组
	//int mid;
	if (low == high)
	{
		temp[low] = arr[low];
	}
	else
	{
		int mid = (low + high) / 2;
		MSort(arr,low,mid,t);    // 左边排序
		MSort(arr,mid+1,high,t); // 右边有序
		Merge(t,low,mid,high,temp);
	}

}

void MergeSort(Record *arr,int len)
{
	MSort(arr,0,len,arr);
}

// 重建堆

void sift(Record *arr,int start,int end)
{
	int i, j;
	i = start;
	j = 2 * i;
	Record temp = arr[i];
	bool finish = false;	
	while (j <= end && ! finish )
	{
		if (j < end&&arr[j].key < arr[j + 1].key)	  // 找到左右子树中较大的一个节点		
			j = j + 1;

		if (arr[j].key > temp.key)					 // 如果当前节点的值大于根节点的值，把当前节点的值复制给根节点,继续往当前节点的左子树上遍历
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

// 堆排序

void HeapSort(Record *arr,int len)				//	 对arr[1...n]进行堆排，执行本算法后，r中记录按关键字由小到大有序排列
{
	int i;
	for (i=len/2;i>=0;i--)						// 初建堆
	{
		sift(arr,i,len);
	}

	for (i=len-1;i>=0;i--)
	{
		Record temp = arr[0];					// 将堆顶记录与堆中最后一个记录进行交换
		arr[0] = arr[i];
		arr[i] = temp;
		sift(arr,0,i-1);						// 顶记录与堆中最后一个记录进行交换后重建堆
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