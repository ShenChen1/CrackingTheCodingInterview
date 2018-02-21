//写一个函数，把字符串中所有的空格替换为%20 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace(char *str)
{
	int size = 0;
	char *p = str;
	char *new;
	while(*p != 0)
	{
		if( *p == ' ')
			size += 3;
		else
			size ++;
		p++;
	}
	size++;
	new = (char *)malloc(size);
	if(new == NULL)
		return NULL;

	p = new;
	while(*str != 0)
	{
		if( *str == ' ')
		{
			strncpy(p, "%20", 3);
			p += 3;
			str++;
		}
		else
			*p++ = *str++;
	}
	*p = 0;

	return new;
}

int main()
{
	char s[] = "shenchen is a boy.";
	printf("%s\n", replace(s));
	
}