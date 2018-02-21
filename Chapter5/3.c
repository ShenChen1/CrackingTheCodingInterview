//给定一个整数x，找出另外两个整数，这两个整数的二进制表示中1的个数和x相同，
//其中一个是比x大的数中最小的，另一个是比x小的数中最大的。


#include <stdio.h>
#include <string.h>

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


int next(int x)
{
	int temp;

	temp = x; 
	while(count_one(x) != count_one(++temp))
		temp++;

	return temp;
}

int previous(int x)
{
	int temp;

	temp = x; 
	while(count_one(x) != count_one(--temp))
		temp--;

	return temp;
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
	int x;
	printf("%d:", -100);show(-100);
	x = next(-100);printf("%d:", x);show(x);
	x = previous(-100);printf("%d:", x);show(x);

}