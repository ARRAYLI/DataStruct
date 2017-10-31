// ����ʵ��

/*

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 40      

// ���ṹ����
typedef struct _String
{
	char ch[MAXSIZE];   
	int len;
}String;

// ����һ��ֵ����sp�е����ݵ��ַ���

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

// �ڴ�s�ĵ�pos���ַ�֮ǰ���봮 t

void StrInsert(String *s,int pos,String *t)
{
	int i;
	if (pos<0||pos>s->len)
	{
		cout << "����λ�ò��Ϸ�!" << endl;
		return;
	}
	else
	{
		// ����󴮳�<=MAXSZIE;

		if (s->len+t->len<=MAXSIZE)    // ��t����ȫ���뵽��s��
		{
			// �ȰѴ�s���ʣ���ַ����ƶ������
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

		// ����󴮳�>MAXSIZE������t���ַ����п���ȫ������,��sʣ��Ĳ����ַ����лᱻ����
		else if(pos+t->len<=MAXSIZE)
		{
			for (i=MAXSIZE-1;i>t->len+pos-1;i--)
			{
				s->ch[i] = s->ch[i - t->len];
			}

			// ��Ҫ������ַ���t���뵽s��posλ�ô�
			for (i=0;i<t->len;i++)
			{
				s->ch[i + pos] = t->ch[i];
			}
			
			s->len = MAXSIZE;
		}
		// ����󴮳�>MAXSIZE �����Ҵ�t�Ĳ����ַ�ҲҪ����
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

// �ڴ�s�ĵ�pos��λ����ɾ������Ϊlen���Ӵ�

void StrDelete(String *s,int pos,int len)
{
	int i;
	if (pos<0||(pos>s->len-len))
	{
		cout << "ɾ��λ�ò��Ϸ�!" << endl;
		return;
	}

	for (i=pos+len;i<s->len;i++)   
	{
		s->ch[i - len] = s->ch[i];  
	}
	s->ch[i - len] = '\0';
	s->len = s->len - len;
}

// �����ƺ���

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

// �пպ���

bool StrEmpty(String s)
{
	if (s.len==0)   // ����sΪ�գ��򷵻�1�����򷵻�0
	{
		return true;
	}
	return false;
}

// ���ȽϺ���

int StrCompare(String s,String t)   // ����s�ʹ�t����򷵻�0;��s>t�򷵻���������s<t�򷵻ظ���
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

// �󴮳�����

// ���ش�s�ĳ���
int StrLength(String s)    
{
	return s.len;
}

// ��պ���
// ����s�ÿ�
void StrClear(String *s)
{
	s->len = 0;
	memset(s->ch,0,MAXSIZE);
}

// �����Ӻ���
// ����t�����ڴ�s�ĺ���

bool StrCat(String *s, String t)
{
	bool flag;
	int i;
	if (s->len + t.len <= MAXSIZE)   // ���Ӻ󴮳�С��MAXSIZE
	{
		for (i = s->len; i < s->len + t.len; i++)
		{
			s->ch[i] = t.ch[i - s->len];
		}
		s->len = s->len + t.len;
		flag = true;
	}
	else if (s->len < MAXSIZE)    // ���Ӻ󴮳�����MAXSIZE������s�ĳ���С��MAXSIZE�������Ӻ�t���ַ���������Ҫ������
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

// ���Ӵ�����
// ����s�±��е�pos��len���ַ����Ƶ�sub��

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

// ���ļ�ģʽƥ��BF�㷨����³��-��˹���㷨
// ������s���±�pos�𣬴�t��һ�γ��ֵ�λ�ã��ɹ��򷵻�λ����ţ����ɹ�����-1��

int StrIndex(String s,int pos,String t)
{
	int i, j, start;
	if (t.len==0)   // ���ģʽ��Ϊ�մ�ʱ�������⴮��ƥ��
	{
		return 0; 
	}
	start = pos;
	i = start;
	j = 0;    // ������pos��ʼ��ģʽ����ͷ(0)��ʼ
	while (i < s.len&&j < t.len)
	{
		if (s.ch[i] == t.ch[j])   // ��ǰ��Ӧ���ַ������ʱ�ƽ�
		{
			i++;
			j++;
		}
		else
		{
			start++;   // ��ǰ��Ӧ�ַ�����ʱ����
			i = start;
			j = 0;
		}
	}
	if (j>=t.len)    // ƥ��ɹ�ʱ������ƥ�����ʼλ��
	{
		return start;
	}
	else      // ƥ�䲻�ɹ����򷵻�-1;
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
	cout << "��t���ĵ�5��λ�ò���s����:" << endl;
	StrInsert(&t, 5, &s);
	cout << t.ch << endl;
	cout << "��t����6��λ��ɾ������Ϊ3���ִ�:" << endl;
	StrDelete(&t, 6, 3);
	cout << t.ch << endl;
	String ss;
	StrCopy(&ss, s);
	cout << "��s�����Ƹ�ss����Ľ���ǣ�" << endl;
	cout << "ss:" << endl << ss.ch << endl;
	if (StrEmpty(t))
	{
		cout << "t��Ϊ�գ�" << endl;
	}
	else
	{
		cout << "t����Ϊ�գ�" << endl;
	}
	cout << "��t�ĳ���Ϊ��" << StrLength(t) << endl;

	StrClear(&ss);
	cout << "����ss���,��պ���ַ���Ϊ��" << ss.ch << endl;

	StrCat(&tt, s);
	cout << "��tt���Ӵ�ss��Ĵ�Ϊ��" << tt.ch << endl;

	int r = StrCompare(tt, s);
	if (r == 0)
	{
		cout << "��tt�ʹ�s�Ƚϣ��������!" << endl;
	}
	else if (r>0)
	{
		cout << "��tt�ʹ�s�Ƚϣ���tt���ڴ�s!" << endl;
	}
	else
	{
		cout << "��tt�ʹ�s�Ƚϣ���ttС�ڴ�s!" << endl;
	}

	String temp;
	temp.len = 0;
	memset(&temp.ch, 0, MAXSIZE);

	if (SubString(&temp, s, 5, 3))
	{
		cout << "��s���±�Ϊ5��ʼ�ĳ���Ϊ3���Ӵ����Ƶ�temp����,temp��Ϊ:" << temp.ch << endl;
	}
	else
	{
		cout << "�޷������ִ���temp����!" << endl;
	}

	cout << s.ch << endl;
	cout << t.ch << endl;
	cout << tt.ch << endl;

	int rr = StrIndex(tt, 0, s);
	if (rr == -1)
	{
		cout << "ƥ�䲻�ɹ�!" << endl;

	}
	else if (rr == 0)
	{
		cout << "ƥ�䴮sΪ��!" << endl;
	}
	else
	{
		cout << "ƥ��ɹ�,tt���г��ִ�s����ʼλ��Ϊ��" << rr << endl;
	}
}

int main(void)
{
	test();
	return 0;
}

*/


// �Ѵ���ʵ��
#include<iostream>
#include<string.h>
using namespace std;

// �Ѵ��Ķ������£�

typedef struct 
{
	char *ch;   // ����ַ�����ָ����
	int len;    // ����ַ����ĳ���
}HString;


// ��ʼ���ַ�������

void _StrInit(HString *s)
{
	s->ch = NULL;
	s->len = 0;
}


//  �Ѵ����뺯��

//�ڴ�s�±�Ϊpos��λ��֮ǰ���봮t

void _StrInsert(HString *s,int pos,HString *t)
{
	int i;
	char *temp;
	if (pos<0||pos>s->len||s->len==0)
	{
		cout << "����λ�ò��Ϸ�!" << endl;
		return;
	}

	temp = new char(s->len + t->len);   // Ϊtemp��̬�����ڴ�
	if (NULL==temp)
	{
		cout << "��̬�����ڴ�ʧ�ܣ�" << endl;
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

// �Ѵ�ɾ������

// �ڴ�s��ɾ���±�pos��len���ַ�

void _StrDelete(HString *s,int pos,int len)
{
	int i;
	char *temp;
	if (pos<0||pos>(s->len-len))
	{
		cout << "ɾ��λ�ò��Ϸ���" << endl;
		return;
	}

	temp= new char(s->len - len);
	if (NULL == temp)
	{
		cout << "��̬�����ڴ�ʧ�ܣ�" << endl;
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

// �Ѵ���ֵ����

// ���ַ�������str��ֵ�����Ѵ�s
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
			cout << "��̬�����ڴ�ʧ��!" << endl;
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

// ���Ժ���

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



