//一张图像表示成NxN的矩阵，图像中每个像素是4个字节，写一个函数把图像旋转90度。
//你能原地进行操作吗？(即不开辟额外的存储空间)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *a, int *b)
{
    	int t;
	t = *a;
    	*a = *b;
    	*b = t;
}
void transpose(void *p, int n)
{
	int i, j;
	int *a = (int *)p;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n -i; j++)
		{
			swap(a+i*n+j, a+(n - j - 1)*n+(n - i - 1));
		}
	}
	for(i = 0; i < n/2; i++)
	{
		for(j = 0; j < n; j++)
		{
			swap(a+i*n+j, a+(n - i - 1)*n+j);
		}
	}
}

void show(void *p, int n)
{
	int i, j;
	int *a = (int *)p;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%2d ", *(a+i*n+j));
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
  	int a[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	show(a, 4);
	transpose(a, 4);
	show(a, 4);

}