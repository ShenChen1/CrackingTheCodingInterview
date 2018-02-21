//写程序交换一个整数二进制表示中的奇数位和偶数位，用尽可能少的代码实现。 
//(比如，第0位和第1位交换，第2位和第3位交换…)

#include <stdio.h>
//5用来提取奇位，A用来提取偶位
int swap_bits(int x)
{
	return ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
}

int show(int x)
{
	int i;
	for(i = 0; i < sizeof(int) * 8; i++)
	{
		printf("%d", x >> (sizeof(int)*8 - 1 - i) & 0x01);
	}
	printf("\n");
}

int main()
{
	int temp;
	temp = swap_bits(234);show(234);
	printf("%d\n", temp);show(temp);

}