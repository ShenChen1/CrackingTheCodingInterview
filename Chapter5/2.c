//给定一个字符串类型(string)表示的小数，打印出它的二进制表示。 
//如果这个数无法精确地表示为二进制形式，输出"ERROR"。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_binary(char *val, char *str)
{
	int flag;
	int integer;
	double decimals;
	int temp;
	int i;
	char *p;
	char str_integer[sizeof(int)*8 + 1];
	char str_decimals[sizeof(int)*8 + 1];

	if((p = strchr(val, '-')) == NULL)
	{
		p = val;
		flag = 0;
	}
	else 
	{
		p++;
		flag = 1;
	}

	integer = atoi(p);
	decimals = atof(p) - integer;

	printf("flag = %d , integer = %d , decimals = %lf\n", flag , integer , decimals);

	for(i = 0; i < sizeof(int)*8; i++)
	{
		temp = (integer >> (sizeof(int)*8 - i - 1)) & 0x01;
		str_integer[i] = '0'+temp;
	}
	str_integer[i] = 0;
	//printf("str_integer:%s\n", str_integer);

	decimals = 1/decimals;
	temp = (int)decimals;
	if(decimals - temp != 0)
	{
		sprintf(str, "ERROR");
		return -1;
	}
	for(i = 0; i < sizeof(int)*8 ; i++)
	{
		temp = ((int)decimals >> (sizeof(int)*8 - i)) & 0x01;
		str_decimals[sizeof(int)*8 - i - 1] = '0'+temp;
	}
	str_decimals[i] = 0;
	//printf("str_decimals:%s\n", str_decimals);

	p = str_decimals;
	for(i = sizeof(int)*8 - 1; i >= 0; i--)
	{
		if(p[i] == '1')
			break;
	}
	p[i + 1] = 0;
	p = str_integer;
	for(i = 0; i < sizeof(int)*8; i++)
	{
		if(*p == '1')
			break;
		p++;
	}
	sprintf(str, "%d%s.%s", flag, p, str_decimals);

	return 0;
}


int main()
{
	char str[64];
	print_binary("12.25", str);printf("str:%s\n", str);
	print_binary("12.26", str);printf("str:%s\n", str);
	print_binary("-12.25", str);printf("str:%s\n", str);
}
