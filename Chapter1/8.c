//��������һ��isSubstring���������Լ��һ���ַ����Ƿ�����һ���ַ������Ӵ��� 
//�����ַ���s1��s2��ֻʹ��һ��isSubstring�����ж�s2�Ƿ���s1����ת�ַ����� ��д�����롣
//��ת�ַ�����"waterbottle"��"erbottlewat"����ת�ַ�����

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isSubstring(char *str1, char *str2)
{
	int len;
	char *str;
	if((len = strlen(str1)) != strlen(str2))
		return -1;

	str = (char *)malloc(2 * len + 1);
	str = strncpy(str, str2, len + 1);
	str = strncat(str, str2, len + 1);
	printf("%s\n", str);
	if(strstr(str, str1) == NULL)
	{
		free(str);
		return -1;
	}
	free(str);
	return 0;
}

int main()
{
	char s1[] = "waterbottle";
	char s2[]	= "erbottlewat";

	printf("%s\n", isSubstring(s1, s2) == 0 ? "is substring" : "is not substring");

	
}