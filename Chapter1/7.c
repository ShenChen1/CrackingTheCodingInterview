//写一个函数处理一个MxN的矩阵，如果矩阵中某个元素为0，那么把它所在的行和列都置为0.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void zero(void *p, int m, int n)
{
	int i, j;
	char *x; 
	char *y; 
	int *a = (int *)p;
	x = (char *)malloc(sizeof(char) * m);
	y = (char *)malloc(sizeof(char) * n);
	memset(x, 0, m);
	memset(y, 0, n);
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(*(a+n*i+j) == 0)
			{
				x[i] = 1;
				y[j] = 1;
				printf("(%d, %d)\n", i, j);
			}
		}
	}
	for(i = 0; i < m; i++)
	{
		if(x[i] == 1)
		{
			for(j = 0; j < n; j++)
			{
				*(a+n*i+j) = 0;
			}
		}
	}
	for(j = 0; j < n; j++)
	{
		if(y[j] == 1)
		{
			for(i = 0; i < m; i++)
			{
				*(a+n*i+j) = 0;
			}
		}
	}
	free(x);
	free(y);
}

void show(void *p, int m, int n)
{
	int i, j;
	int *a = (int *)p;
	for(i = 0; i < m; i++)
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
  	int a[3][5] = {
		{1, 2, 3, 4, 0},
		{5, 1, 6, 7, 8},
		{0, 9, 10, 11, 12},
	};
	show(a, 3, 5);
	zero(a, 3, 5);
	show(a, 3, 5);

}
