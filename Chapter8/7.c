//我们有25分，10分，5分和1分的硬币无限个。
//写一个函数计算组成n分的方式有几种？

#include <stdio.h>


int sumn(int n)
{
	int x, y, z;
	int a, b ,c;

	if(n < 0)
		return -1;

	a = n /25 + 1;
	b = n /10 + 1;

	for(x = 0; x < a; x++)
	{
		for(y = 0; y < b; y++)
		{
			if(25*x + 10*y > n)
				continue;
			z = n - 25*x - 10*y;
			printf("%d:%d, %d, %d\n", n, x, y, z);
		}
	}
	return 0;
}


int main()
{
	sumn(0);
	sumn(10);
	sumn(25);
}




