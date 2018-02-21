//数组A[1…n]包含0到n的所有整数，但有一个整数丢失了。
//在这个问题中， 我们不能直接通过A[i]取得数组中的第i个数。
//数组A被表示成二进制， 也就是一串的0/1字符，而我们唯一能使用的操作只有“取得A[i]中的第j位”，
//这个操作只需要花费常数时间。写程序找出丢失的整数，你能使程序的时间复杂度是O(n)吗？


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int missing(int a[], int n)
{
	int i, j;
	int temp;
	int *p;
	p = (int *)malloc(sizeof(int) * n);
	memset(p, 0, sizeof(int) * n);

	for(i = 0; i < n; i++)
	{
		for(j = sizeof(int)*8 - 1; j >=0; j--)
			temp = (temp << 1) | ((a[i]>>j) & 0x01);
		//printf("%d\n", temp);
		p[temp - 1] = 1;
	}
	for(i = 0; i < n; i++)
	{
		if(p[i] == 0)
			return i+1;
	}

	return -1;
}


int main()
{
	int a[] = {0, 1, 2, 3, 5};
	printf("%d\n", missing(a, 5));
}