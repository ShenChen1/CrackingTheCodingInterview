//写一个函数判断两个字符串是否是变位词。

#include <stdio.h>
#include <string.h>

int isAnagram(char *str1, char *str2)
{
	int i;
	int c[256] = {0};
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if(len1 != len2)
		return -1;
	for(i =0; i < len1; i++)
	{
		++c[*str1++];
		--c[*str2++];
	}
	for(i = 0; i < 256; i++)
	{
		if(c[i] != 0)
			return -1;
	}

	return 0;
}

int main()
{
	char s1[] = "shenchen";
	char s2[] = "cnsheneh";

	printf("%s\n", isAnagram(s1, s2) == 0 ? "is anagram" : "is not anagrams");


}