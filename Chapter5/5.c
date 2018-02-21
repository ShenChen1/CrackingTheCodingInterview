//写程序计算从整数A变为整数B需要修改的二进制位数。

#include <stdio.h>

int count_one(int a)
{
	int count  = 0;
	int i;
	for(i = 0; i < sizeof(int)*8; i++)
	{
		if((a >> i) & 0x01)
			count++;
	}

	return count;
}

int convert_num(int a, int b)
{
	int temp;

	temp = a ^ b;

	return count_one(temp);
}

void show(int n)
{
	int i;
	for(i = 0; i < sizeof(int) * 8; i++)
	{
		printf("%d", (n >> (sizeof(int) * 8 -1 - i) )& 0x01);
	}
	printf("\n");
}


int main()
{
	show(14);
	show(9);
	printf("%d\n", convert_num(14, 9));
}

