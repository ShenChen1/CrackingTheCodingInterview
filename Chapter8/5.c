//ʵ��һ���㷨��ӡ��n�����ŵ���Ч��ϡ�
//���磺
//���룺3 ��3�����ţ�
//�����((())), (()()), (())(), ()(()), ()()()

#include <stdio.h>
#include <stdlib.h>

void print_pare(int left, int right, int n, char *p)
{
	int i;
	
	if(left < 0 || right < left)
	{
		return;
	}
	if(left == 0 && right == 0)
	{
		p[n] = 0;
		printf("%s", p);
		printf("%c", ',');	
	}
	else
	{
		if(left > 0)
		{
			p[n] = '(';
			print_pare(left - 1, right, n + 1, p);

		}
		if(right > left)
		{
			p[n] = ')';
			print_pare(left, right - 1, n + 1, p);

		}
	}
}

#define N 3

int main()
{
	char p[N*2+1];
	print_pare(N, N, 0, p);


}