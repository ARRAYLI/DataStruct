
#include<iostream>
using namespace std;
#define LEN 8

int amount = 0;    // 总共棋盘数

bool IsNoDanger(int row, int k, int(*chess)[LEN])
{
	int i, j;

	// 判断列方向

	for (i=0;i<LEN;i++)
	{
		if (chess[i][k]==1)   // 如果某行的某一列这个位置出现皇后，则处于危险状态，退出
		{
			return false;
		}
	}


	// 判断左上方
	for (i = row, j = k; i >= 0 && j >= 0; i--, j--)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}


	//  判断右下方
	for (i=row,j=k;i<LEN&&j<LEN;i++,j++)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}

	// 判断右上方

	for (i=row,j=k;i>=0&&j<LEN;i--,j++)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}

	// 判断左下方
	for (i=row,j=k;i<LEN&&j>=0;i++,j--)
	{
		if (chess[i][j]==1)
		{
			return false;
		}
	}
	return true;
}


// row 代表起始行    clo 表示列数  (*chess)[LEN]  指向棋盘每一行的指针

void EightQueue(int row,int clo,int (*chess)[LEN])   
{
	int chess2[LEN][LEN];   // 创建临时棋盘存放当前的棋盘
	int i, j;

	// 赋值原棋盘
	for (i=0;i<LEN;i++)
	{
		for (j=0;j<LEN;j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if (row==LEN)       // 如果起始行==LEN，即 row==8 时,打印出棋盘
	{
		amount++;
		cout << "第"<<amount<<"种:"<< endl;

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
		// 判断这个位置是否有危险，如果有危险，则进行继续往下

		for (j=0;j<clo;j++)    
		{
			if (IsNoDanger(row, j, chess))   // 判断是否有危险
			{
				for (i = 0; i < LEN; i++)
					chess2[row][i] = 0;    // 没有危险，标记为0

				chess2[row][j] = 1;        // 有危险，标记为1
				EightQueue(row + 1, clo, chess2);
			}
		}
	}

}

int main(void)
{
	int chess[LEN][LEN] = { 0 };    // 初始化棋盘为0

	EightQueue(0,LEN, chess);
	return 0;
}




/*

#include <stdio.h>  
#include <stdlib.h>  

int count;
//递归法实现八皇后问题  

//参数row表示起始行，参数n表示列数  
//参数(*chess)[8]表示指向棋盘每一行的指针  

int notdanger(int row, int j, int(*chess)[8]) {
	int i, k;
	//判断列方向  
	for (i = 0; i<8; i++) {

		if(chess[i][j]==1){
	//	if (*(*(chess + i) + j) == 1) {//这一列已存在皇后  
			return 0;
		}
	}
	//判断左上方  
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--) {
		if(chess[i][k]==1)
		//if (*(*(chess + i) + k) == 1)
		{
			return 0;
		}
	}
	//判断右下方  
	for (i = row, k = j; i<8 && k<8; i++, k++) {
		
		if(chess[i][k]==1)
	//	if (*(*(chess + i) + k) == 1) 
		{
			return 0;
		}
	}
	//判断左下方  
	for (i = row, k = j; i<8 && k >= 0; i++, k--) {
		if(chess[i][k]==1)
	//	if (*(*(chess + i) + k) == 1)
		{
			return 0;
		}
	}
	//判断右上方  
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
		printf("第%d种：\n", ++count);
		for (i = 0; i<8; i++) {
			for (j = 0; j<8; j++) {
			//	printf("%d ", *(*(chess2 + i) + j));
				printf("%d ", chess2[i][j]);
			}
			printf("\n");
		}
	}
	else {
		//判断这个位置是否有危险  
		//如果有危险，那继续往下  
		for (j = 0; j<n; j++) {
			if (notdanger(row, j, chess)) {//判断是否危险  
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
	//初始化棋盘为0  
	for (i = 0; i<8; i++) {
		for (j = 0; j<8; j++) {
			chess[i][j] = 0;
		}
	}
	eightqueen(0, 8, chess);//从第0行开始依次以行为单位遍历  
	return 0;
}

*/