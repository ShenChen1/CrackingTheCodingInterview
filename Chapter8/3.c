//写一个函数返回一个集合中的所有子集。


#include <stdio.h>
#include <stdlib.h>

int subsets(int a[], int n)
{
	int *p;
	int i, j, c;
	int temp = 1;
	if(a == NULL || n < 1)
		return -1;

	p = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
	{
		p[i] = 0;//初始化
		temp *= 2;//计算一共有多少子集
	}

	for(i = 0; i < temp; i++)
	{
		c = 0;
		for(j = 0; j < n; j++)
		{
			if(p[j] == 1)
				printf("%d", a[j]);

			p[j] += c;
			if(p[j] == 1)
				c = 0;
			else if(p[j] == 2)
			{
				c = 1;
				p[j] = 0;
			}
		}
		printf("\n");
	}

	free(p);
	return temp;
}



int main()
{
	int a[] = {1, 2, 3, 4, 5};
	subsets(a, sizeof(a)/sizeof(int));

}
