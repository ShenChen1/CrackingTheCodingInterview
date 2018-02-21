//假设你有一个isSubstring函数，可以检测一个字符串是否是另一个字符串的子串。 
//给出字符串s1和s2，只使用一次isSubstring就能判断s2是否是s1的旋转字符串， 请写出代码。
//旋转字符串："waterbottle"是"erbottlewat"的旋转字符串。

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