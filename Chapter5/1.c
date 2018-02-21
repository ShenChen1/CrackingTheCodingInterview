//给定两个32位的数，N和M，还有两个指示位的数，i和j。 
//写程序使得N中第i位到第j位的值与M中的相同(即：M变成N的子串且位于N的第i位和第j位之间)
//例子：
//输入: N = 10000000000, M = 10101, i = 2, j = 6
//输出: N = 10001010100

#include <stdio.h>
#include <stdlib.h>

void show(int n)
{
	int i;
	for(i = 0; i < sizeof(int) * 8; i++)
	{
		printf("%d", (n >> (sizeof(int) * 8 -1 - i) )& 0x01);
	}
	printf("\n");
}


int update_bits(int n, int m, int i, int j)
{
	int x;
	show(m);
	show(n);
	m = m << i;
	for(x = j + 1; x < sizeof(int) * 8; x++)
	{
		m &= ~((int)0x01<< x);
	}
	show(m);
	for(x = i; x <= j; x++)
	{
		n &= ~((int)0x01 << x);
		n |= m & (0x01 << x);
	}
	show(n);
	return 0;
}


int main()
{
	 update_bits(1024, 21, 2, 6);
	 update_bits(200, 21, 2, 6);

}