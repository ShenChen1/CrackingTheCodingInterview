//写代码翻转一个C风格的字符串。(C风格的意思是"abcd"需要用5个字符来表示，包含末尾的 结束字符)

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