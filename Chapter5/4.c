//������´�������ã�((n & (n-1)) == 0)

#include <stdio.h>


//������������ж�һ�����Ƿ�Ϊ2���������ݡ���Ŀ�е��жϴ��벻���Ͻ��� ��Ϊ��n=0ʱ����������Ϊ�棬��0������2���ݡ�
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