//����㷨��д�������Ƴ��ַ������ظ����ַ�������ʹ�ö���Ļ���ռ䡣
//ע�⣺ ����ʹ�ö����һ��������������������������ٿ�һ�����鿽����


#include <stdio.h>
#include <string.h>

void removeDuplicate(char *str)
{
	int i,j;
	char *p = str;
	int char_statue[4] = {0, 0, 0, 0};
	while(*p != 0)
	{
		i = *p /32;
		j = *p%32;
		if((char_statue[i] >> j) & 0x1 == 0x1)
		{
			p++;
			continue;
		}
		char_statue[i] |= (0x1 << j);
		*str++ = *p++;		
	}
	*str = 0;
}

int main()
{
	char ss1[] = "abcde";
    	char ss2[] = "aaabbb";
   	char ss3[] = "";
   	char ss4[] = "abababc";
   	char ss5[] = "ccccc";

	removeDuplicate(ss1);
	removeDuplicate(ss2);
	removeDuplicate(ss3);
	removeDuplicate(ss4);
	removeDuplicate(ss5);

	printf("%s\n", ss1);
	printf("%s\n", ss2);
	printf("%s\n", ss3);
	printf("%s\n", ss4);
	printf("%s\n", ss5);
	
}