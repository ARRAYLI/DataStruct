// KMP 算法
#if 0
#include<iostream>
#define MAXSIZE 20
using namespace std;

void getNext(char *str,int next[])
{
	int i = 0;
	int j = -1;
	next[0] = -1;

	while (str[i]!='\0')
	{
		if (j==-1||str[i]==str[j])		
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP(char *s,char *t)
{
	int next[MAXSIZE] = { 0 };
	getNext(t,next);
	for (int k=0;k<strlen(t);k++)
	{
		cout << next[k] << " ";
	}
	cout << endl;
	int i, j;
	i = 0; 
	j = 0;
	while (s[i]!='\0'&&j<strlen(t))
	{
		if (s[i]==t[j])
		{
			i++; 
			j++;
			if (j==strlen(t))
			{
				return i - j;
			}
		}
		else
		{
			j = next[j];
		}
		if (j==-1)
		{
			i++;
			j++;
		}
	}
	return -1;
}


int main(void)
{
	
	char s[] = "ABCDABCDEABCD";
	char t[] = "ABCDE";
	int res = KMP(s,t);
	cout << res << endl;

	return 0;
}

#endif

#if 0
#include<iostream>
#define MAXSIZE 20
using namespace std;

int BF(char *str,int len1,char *dst,int len2)
{
	int i=0, j=0;
	int start =i;

	while (i<len1&&j < len2)
	{
		if (str[i] == dst[j])
		{
			i++;
			j++;
		}
		else
		{
			start++;
			i = start;
			j = 0;
		}
	}
	if (j >=len2)
	{
		return start;
	}
	else
		return -1;
}

void getNext(char*dst,int next[],int len)
{
	int i = 0;
	int j = -1;
	next[0] = -1;

	while (dst[i]!='\0'&&j<len)
	{
		if (j == -1 || dst[i] == dst[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int KMP(char *src,char *dst)
{
	int next[MAXSIZE] = { 0 };
	int len = strlen(dst);
	getNext(dst,next,len);
	int i = 0;
	int j = 0;
	while (src[i]!='\0')
	{
		if (j==-1||src[i]==dst[j])
		{
			i++;
			j++;
			if (j==len)
			{
				return i - len;
			}
		}
		else
		{
			j = next[j];
		}
	}
	return -1;
}

int main(void)
{
	char src[] = "ABCDBCDABCD";
	char dst[] = "BCDA";
	int len1 = strlen(src);
	int len2 = strlen(dst);
	int res = 0;
//	res= BF(src, len1, dst, len2);
	res = KMP(src,dst);
	cout << res << endl;
	return 0;
}
#endif

#if 1
#include<iostream>
using namespace std;
#define MAXSIZE 20

void getNext(char *dst,int next[])
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (dst[i]!='\0')
	{
		if (j == -1 || dst[i] == dst[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else    
			j=next[j];	
	}
}

int KMP(char *src,char *dst)
{
	int i = 0;
	int j = 0;
	int next[MAXSIZE] = { 0 };
	getNext(dst,next);
	cout << "输出next数组:" << endl;
	for (int k=0;k<strlen(dst);k++)
	{
		cout << next[k] << " ";
	}
	cout << endl;

	while (src[i]!='\0'&&j<strlen(dst))
	{
		if (src[i] == dst[j])
		{
			i++;
			j++;
			if (j==strlen(dst))
			{
				return i -j;
			}
		}
		else
			j = next[j];
		if (j == -1)
		{
			i++;
			j++;
		}
	}

	return -1;
}

int main(void)
{

//	char src[] = "ABCDABCDEABCD";
//	char dst[] = "ABCDE";
	char src[] = "ABCDBCDCDBDCDBAD";
	char dst[] = "DCDBA";
	int res = 0;
	res = KMP(src,dst);
	cout << res << endl;
	return 0;
}

#endif