//д���뷭תһ��C�����ַ�����(C������˼��"abcd"��Ҫ��5���ַ�����ʾ������ĩβ�� �����ַ�)

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

char *reverse(char *str)
{
	int i;
	int len = strlen(str);
	for(i = 0; i < len / 2 ; i++)
	{
		swap(&str[i], &str[len - i - 1]);
	}

	return str;
}
int main()
{
	char s1[] = "shenchen";
	printf("%s\n", reverse(s1));
}