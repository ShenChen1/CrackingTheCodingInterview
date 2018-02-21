//解答以下代码的作用：((n & (n-1)) == 0)

#include <stdio.h>


//代码的作用是判断一个数是否为2的整数次幂。题目中的判断代码不够严谨， 因为当n=0时，上述条件为真，但0并不是2的幂。
int  isInteger_power_of_two(int n)
{
	int temp;
	int i;
	
	if(n <= 0)
		return -2;

	if((n & (n-1)) != 0)
		return -1;

	temp = 1;
	i = 0;
	while(temp != n)
	{
		temp *= 2;
		i++;
	}

	return i;
}


int main()
{
	 printf("%d\n", isInteger_power_of_two(2));
	 printf("%d\n", isInteger_power_of_two(256));
	 printf("%d\n", isInteger_power_of_two(12));
	 printf("%d\n", isInteger_power_of_two(0));
}