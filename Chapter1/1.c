//实现一个算法来判断一个字符串中的字符是否唯一(即没有重复).不能使用额外的数据结构。 (即只使用基本的数据结构)

#include <stdio.h>
#include <string.h>

//将ascii（128个字符）按位存放，当某字符第一次出现时，就置位，
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