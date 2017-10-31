// 串的实现

/*

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 40      

// 串结构定义
typedef struct _String
{
	char ch[MAXSIZE];   
	int len;
}String;

// 生成一个值等于sp中的内容的字符串

void StrAgain(String *s,char *sp)
{
	int i;
	s->len = 0;
	memset(s->ch,0,MAXSIZE);
	for (i=0;sp[i]!='\0';i++)
	{
		s->ch[i] = sp[i];
		s->len++;
	}
	s->ch[i] = '\0';
}

// 在串s的第pos个字符之前插入串 t

void StrInsert(String *s,int pos,String *t)
{
	int i;
	if (pos<0||pos>s->len)
	{
		cout << "插入位置不合法!" << endl;
		return;
	}
	else
	{
		// 插入后串长<=MAXSZIE;

		if (s->len+t->len<=MAXSIZE)    // 串t被完全插入到串s中
		{
			// 先把串s后的剩余字符串移动到最后
			for (i=s->len+t->len-1;i>=t->len+pos;i--)
			{
				s->ch[i] = s->ch[i - t->len];
			}

			for (i=0;i<t->len;i++)
			{
				s->ch[i + pos] = t->ch[i];
			}

			s->len = s->len + t->len;
		}

		// 插入后串长>MAXSIZE，但串t的字符序列可以全部插入,串s剩余的部分字符序列会被舍弃
		else if(pos+t->len<=MAXSIZE)
		{
			for (i=MAXSIZE-1;i>t->len+pos-1;i--)
			{
				s->ch[i] = s->ch[i - t->len];
			}

			// 把要插入的字符串t插入到s的pos位置处
			for (i=0;i<t->len;i++)
			{
				s->ch[i + pos] = t->ch[i];
			}
			
			s->len = MAXSIZE;
		}
		// 插入后串长>MAXSIZE ，并且串t的部分字符也要舍弃
		else
		{
			for (i=0;i<MAXSIZE;i++)
			{
				s->ch[pos + i] = t->ch[i];

			}
			s->len = MAXSIZE;
		}
	}
}

// 在串s的第pos个位置起删除长度为len的子串

void StrDelete(String *s,int pos,int len)
{
	int i;
	if (pos<0||(pos>s->len-len))
	{
		cout << "删除位置不合法!" << endl;
		return;
	}

	for (i=pos+len;i<s->len;i++)   
	{
		s->ch[i - len] = s->ch[i];  
	}
	s->ch[i - len] = '\0';
	s->len = s->len - len;
}

// 串复制函数

void StrCopy(String *s,String t)
{
	int i;
	for (i=0;i<t.len;i++)
	{
		s->ch[i] = t.ch[i];
	}
	s->ch[t.len] = '\0';
	s->len = t.len;
}

// 判空函数

bool StrEmpty(String s)
{
	if (s.len==0)   // 若串s为空，则返回1，否则返回0
	{
		return true;
	}
	return false;
}

// 串比较函数

int StrCompare(String s,String t)   // 若串s和串t相等则返回0;若s>t则返回正数；若s<t则返回负数
{
	int i;
	for (i=0;i<s.len&&i<t.len;i++)
	{
		if (s.ch[i]!=t.ch[i])
		{
			return s.ch[i]- t.ch[i];
		}
	}
	return s.len - t.len;
}

// 求串长函数

// 返回串s的长度
int StrLength(String s)    
{
	return s.len;
}

// 清空函数
// 将串s置空
void StrClear(String *s)
{
	s->len = 0;
	memset(s->ch,0,MAXSIZE);
}

// 串连接函数
// 将串t连接在串s的后面

bool StrCat(String *s, String t)
{
	bool flag;
	int i;
	if (s->len + t.len <= MAXSIZE)   // 连接后串长小于MAXSIZE
	{
		for (i = s->len; i < s->len + t.len; i++)
		{
			s->ch[i] = t.ch[i - s->len];
		}
		s->len = s->len + t.len;
		flag = true;
	}
	else if (s->len < MAXSIZE)    // 连接后串长大于MAXSIZE，但串s的长度小于MAXSIZE，即连接后串t的字符部分序列要被舍弃
	{
		for (i = s->len; i < MAXSIZE; i++)
		{
			s->ch[i] = t.ch[i - s->len];
		}
		s->len = MAXSIZE;
		flag = false;
	}
	else
		flag = false;
	return flag;
}

// 求子串函数
// 将串s下标中的pos起len个字符复制到sub中

bool SubString(String *sub,String s,int pos,int len)
{
	int i;
	if (pos<0||pos>s.len||len<1||len>s.len-pos)
	{
		sub->len = 0;
		memset(sub->ch,0,MAXSIZE);
		return false;
	}
	else
	{
		for (i=0;i<len;i++)
		{
			sub->ch[i] = s.ch[i + pos];
		}
		sub->len = len;
		return true;
	}
}

// 串的简单模式匹配BF算法（布鲁特-福斯）算法
// 从主串s的下标pos起，串t第一次出现的位置，成功则返回位置序号，不成功返回-1；

int StrIndex(String s,int pos,String t)
{
	int i, j, start;
	if (t.len==0)   // 如果模式串为空串时，是任意串的匹配
	{
		return 0; 
	}
	start = pos;
	i = start;
	j = 0;    // 主串从pos开始，模式串从头(0)开始
	while (i < s.len&&j < t.len)
	{
		if (s.ch[i] == t.ch[j])   // 当前对应的字符串相等时推进
		{
			i++;
			j++;
		}
		else
		{
			start++;   // 当前对应字符不等时回溯
			i = start;
			j = 0;
		}
	}
	if (j>=t.len)    // 匹配成功时，返回匹配的起始位置
	{
		return start;
	}
	else      // 匹配不成功，则返回-1;
		return -1;  
}

void test(void)
{
	String s;
	String t;
	String tt;
	StrAgain(&s, "HelloWorld");
	StrAgain(&t, "HelloCPP");
	StrAgain(&tt, "HelloCPP");
	cout << "s:" << endl << s.ch << endl;
	cout << "t:" << endl << t.ch << endl;
	cout << "tt:" << endl << tt.ch << endl;
	cout << "给t串的第5个位置插入s串后:" << endl;
	StrInsert(&t, 5, &s);
	cout << t.ch << endl;
	cout << "给t串第6给位置删除长度为3的字串:" << endl;
	StrDelete(&t, 6, 3);
	cout << t.ch << endl;
	String ss;
	StrCopy(&ss, s);
	cout << "把s串复制给ss串后的结果是：" << endl;
	cout << "ss:" << endl << ss.ch << endl;
	if (StrEmpty(t))
	{
		cout << "t串为空！" << endl;
	}
	else
	{
		cout << "t串不为空！" << endl;
	}
	cout << "串t的长度为：" << StrLength(t) << endl;

	StrClear(&ss);
	cout << "给串ss清空,清空后的字符串为：" << ss.ch << endl;

	StrCat(&tt, s);
	cout << "串tt连接串ss后的串为：" << tt.ch << endl;

	int r = StrCompare(tt, s);
	if (r == 0)
	{
		cout << "串tt和串s比较，两串相等!" << endl;
	}
	else if (r>0)
	{
		cout << "串tt和串s比较，串tt大于串s!" << endl;
	}
	else
	{
		cout << "串tt和串s比较，串tt小于串s!" << endl;
	}

	String temp;
	temp.len = 0;
	memset(&temp.ch, 0, MAXSIZE);

	if (SubString(&temp, s, 5, 3))
	{
		cout << "把s的下标为5开始的长度为3的子串复制到temp串中,temp串为:" << temp.ch << endl;
	}
	else
	{
		cout << "无法复制字串到temp串中!" << endl;
	}

	cout << s.ch << endl;
	cout << t.ch << endl;
	cout << tt.ch << endl;

	int rr = StrIndex(tt, 0, s);
	if (rr == -1)
	{
		cout << "匹配不成功!" << endl;

	}
	else if (rr == 0)
	{
		cout << "匹配串s为空!" << endl;
	}
	else
	{
		cout << "匹配成功,tt串中出现串s的起始位置为：" << rr << endl;
	}
}

int main(void)
{
	test();
	return 0;
}

*/


// 堆串的实现
#include<iostream>
#include<string.h>
using namespace std;

// 堆串的定义如下：

typedef struct 
{
	char *ch;   // 存放字符串的指针域
	int len;    // 存放字符串的长度
}HString;


// 初始化字符串函数

void _StrInit(HString *s)
{
	s->ch = NULL;
	s->len = 0;
}


//  堆串插入函数

//在串s下标为pos的位置之前插入串t

void _StrInsert(HString *s,int pos,HString *t)
{
	int i;
	char *temp;
	if (pos<0||pos>s->len||s->len==0)
	{
		cout << "插入位置不合法!" << endl;
		return;
	}

	temp = new char(s->len + t->len);   // 为temp动态分配内存
	if (NULL==temp)
	{
		cout << "动态申请内存失败！" << endl;
		return;
	}
	for (i=0;i<pos;i++)
	{
		temp[i] = s->ch[i];
	}

	for (i=0;i<t->len;i++)
	{
		temp[i + pos] = t->ch[i];
	}

	for (i=pos;i<s->len;i++)
	{
		temp[i + t->len] = s->ch[i];
	}
	temp[s->len+t->len] = '\0';

	s->len += t->len;
	delete s->ch; 
	s->ch = temp;
}

// 堆串删除函数

// 在串s中删除下标pos起len个字符

void _StrDelete(HString *s,int pos,int len)
{
	int i;
	char *temp;
	if (pos<0||pos>(s->len-len))
	{
		cout << "删除位置不合法！" << endl;
		return;
	}

	temp= new char(s->len - len);
	if (NULL == temp)
	{
		cout << "动态申请内存失败！" << endl;
		return;
	}

	for (i = 0; i < pos; i++)
	{
		temp[i] = s->ch[i];
	}

	for (i=pos;i<s->len-len;i++)
	{
		temp[i] = s->ch[i + len];
	}
	temp[i] = '\0';
	s->len -= len;
	delete s->ch;
	s->ch = temp;
}

// 堆串赋值函数

// 将字符串常量str的值赋给堆串s
void _StrAssign(HString *s, char *str)
{
	int len, i = 0;
	char *temp;
	if (s->ch!=NULL)
	{
		delete s->ch;
		s->ch = NULL;
		s->len = 0;
	}
	while (str[i]!='\0')  i++;
	len = i;
	if (len)
	{
		temp = new char(len);
		if (NULL == temp)
		{
			cout << "动态申请内存失败!" << endl;
			return;
		}
		for (i = 0; i < len; i++)
		{
			temp[i] = str[i];
		}
		temp[i] = '\0';
		s->ch = temp;
		s->len += len;
	}
	else
		s->ch = NULL;
}

// 测试函数

void test(void)
{
	HString s;
	_StrInit(&s);
	_StrAssign(&s,"Hello World");
	cout << s.ch <<"    "<< s.len << endl;
    
	HString t;
	_StrInit(&t);
	_StrAssign(&t, "I Love You");
	cout << t.ch << "    " << t.len << endl;

//	_StrInsert(&s,5,&t);
//	cout << s.ch << "  "<<s.len << endl;







}

int main(void)
{
	/*char *s = "HABC";
	cout << strlen(s) << endl;
	cout << sizeof(s) << endl;
*/
	test();
	return 0;
}



