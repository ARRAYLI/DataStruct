
#include<iostream>
using namespace std;
#define LEN 8

int amount = 0;    // �ܹ�������

bool IsNoDanger(int row, int k, int(*chess)[LEN])
{
	int i, j;

	// �ж��з���

	for (i=0;i<LEN;i++)
	{
		if (chess[i][k]==1)   // ���ĳ�е�ĳһ�����λ�ó��ֻʺ�����Σ��״̬���˳�
		{
			return false;
		}
	}


	// �ж����Ϸ�
	for (i = row, j = k; i >= 0 && j >= 0; i--, j--)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}


	//  �ж����·�
	for (i=row,j=k;i<LEN&&j<LEN;i++,j++)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}

	// �ж����Ϸ�

	for (i=row,j=k;i>=0&&j<LEN;i--,j++)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}

	// �ж����·�
	for (i=row,j=k;i<LEN&&j>=0;i++,j--)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}
	return true;
}


// row ������ʼ��    clo ��ʾ����  (*chess)[LEN]  ָ������ÿһ�е�ָ��

void EightQueue(int row,int clo,int (*chess)[LEN])   
{
	int chess2[LEN][LEN];   // ������ʱ���̴�ŵ�ǰ������
	int i, j;

	// ��ֵԭ����
	for (i=0;i<LEN;i++)
	{
		for (j=0;j<LEN;j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if (row==LEN)       // �����ʼ��==LEN���� row==8 ʱ,��ӡ������
	{
		amount++;
		cout << "��"<<amount<<"��:"<< endl;

		for(i=0;i<LEN;i++)
		{
			for (j=0;j<LEN;j++)
			{
				cout << chess2[i][j] << "  ";
			}
			cout << endl;
		}
	}
	else
	{
		// �ж����λ���Ƿ���Σ�գ������Σ�գ�����м�������

		for (j=0;j<clo;j++)    
		{
			if (IsNoDanger(row, j, chess))   // �ж��Ƿ���Σ��
			{
				for (i = 0; i < LEN; i++)
					chess2[row][i] = 0;    // û��Σ�գ����Ϊ0

				chess2[row][j] = 1;        // ��Σ�գ����Ϊ1
				EightQueue(row + 1, clo, chess2);
			}
		}
	}

}

int main(void)
{
	int chess[LEN][LEN] = { 0 };    // ��ʼ������Ϊ0

	EightQueue(0,LEN, chess);
	return 0;
}




/*

#include <stdio.h>  
#include <stdlib.h>  

int count;
//�ݹ鷨ʵ�ְ˻ʺ�����  

//����row��ʾ��ʼ�У�����n��ʾ����  
//����(*chess)[8]��ʾָ������ÿһ�е�ָ��  

int notdanger(int row, int j, int(*chess)[8]) {
	int i, k;
	//�ж��з���  
	for (i = 0; i<8; i++) {

		if(chess[i][j]==1){
	//	if (*(*(chess + i) + j) == 1) {//��һ���Ѵ��ڻʺ�  
			return 0;
		}
	}
	//�ж����Ϸ�  
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--) {
		if(chess[i][k]==1)
		//if (*(*(chess + i) + k) == 1)
		{
			return 0;
		}
	}
	//�ж����·�  
	for (i = row, k = j; i<8 && k<8; i++, k++) {
		
		if(chess[i][k]==1)
	//	if (*(*(chess + i) + k) == 1) 
		{
			return 0;
		}
	}
	//�ж����·�  
	for (i = row, k = j; i<8 && k >= 0; i++, k--) {
		if(chess[i][k]==1)
	//	if (*(*(chess + i) + k) == 1)
		{
			return 0;
		}
	}
	//�ж����Ϸ�  
	for (i = row, k = j; i >= 0 && k<8; i--, k++) {
		if(chess[i][k]==1)
	//	if (*(*(chess + i) + k) == 1) 
		{
			return 0;
		}
	}
	return 1;
}

void eightqueen(int row, int n, int(*chess)[8]) {
	int chess2[8][8], i, j;
	for (i = 0; i<8; i++) {
		for (j = 0; j<8; j++) {
			chess2[i][j] = chess[i][j];
		}
	}
	if (row == 8) {
		printf("��%d�֣�\n", ++count);
		for (i = 0; i<8; i++) {
			for (j = 0; j<8; j++) {
			//	printf("%d ", *(*(chess2 + i) + j));
				printf("%d ", chess2[i][j]);
			}
			printf("\n");
		}
	}
	else {
		//�ж����λ���Ƿ���Σ��  
		//�����Σ�գ��Ǽ�������  
		for (j = 0; j<n; j++) {
			if (notdanger(row, j, chess)) {//�ж��Ƿ�Σ��  
				for (i = 0; i<8; i++) 
				{
				//	*(*(chess2 + row) + i) = 0;
					chess2[row][i] = 0;
				}
			//	*(*(chess2 + row) + j) = 1;
				chess2[row][j] = 1;
				eightqueen(row + 1, n, chess2);
			}
		}
	}
}

int main()
{
	int chess[8][8];
	int i, j;
	//��ʼ������Ϊ0  
	for (i = 0; i<8; i++) {
		for (j = 0; j<8; j++) {
			chess[i][j] = 0;
		}
	}
	eightqueen(0, 8, chess);//�ӵ�0�п�ʼ��������Ϊ��λ����  
	return 0;
}

*/