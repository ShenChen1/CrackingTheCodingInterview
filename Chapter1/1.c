//ʵ��һ���㷨���ж�һ���ַ����е��ַ��Ƿ�Ψһ(��û���ظ�).����ʹ�ö�������ݽṹ�� (��ֻʹ�û��������ݽṹ)

#include <stdio.h>
#include <string.h>

//��ascii��128���ַ�����λ��ţ���ĳ�ַ���һ�γ���ʱ������λ��
int isUnique(char *str)
{
	char *p;
	unsigned int char_statue[4] = {0, 0, 0, 0};
	int i, j;
	p = str;
	while(*p != 0)
	{
		i = *p /32;
		j = *p%32;
		if((char_statue[i] >> j) & 0x1 == 0x1)
			return -1;
		char_statue[i] |= (0x1 << j);
		p++;
	}

	return 0;
}

int main()
{
	char s1[] = "i am shenchen.";
   	char s2[] = "abcdefghijklmnopqrstuvwxyzABCD1234567890";
  	printf("%s\n", isUnique(s1) == 0 ? "is unique" : "is not unique");
	printf("%s\n", isUnique(s2) == 0 ? "is unique" : "is not unique");
    
    return 0;


}