//写一个函数来产生第n个斐波那契数。

#include <stdio.h>

int fibonacci1(int n)
{
	if(n < 1)
		return -1;
	
	if(n == 1 || n == 2)
		return 1;

	return fibonacci1(n - 1) + fibonacci1(n - 2);

}

int fibonacci2(int n)
{
	int a, b;
	int i;
	a = 1;
	b = 1;
	i = 1;

	if(n < 1)
		return -1;

	while(1)
	{
		if(i == n)
			return a;
		a = a + b;
		i++;
		if(i == n)
			return b;
		b = a +b ;
		i++;
	}

}
	
int main()
{
	int i;
	for(i = 0; i < 10; i++)
		printf("%d:%d\n", i, fibonacci2(i));
	
}