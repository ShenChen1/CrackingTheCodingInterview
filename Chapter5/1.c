//��������32λ������N��M����������ָʾλ������i��j�� 
//д����ʹ��N�е�iλ����jλ��ֵ��M�е���ͬ(����M���N���Ӵ���λ��N�ĵ�iλ�͵�jλ֮��)
//���ӣ�
//����: N = 10000000000, M = 10101, i = 2, j = 6
//���: N = 10001010100

#include <stdio.h>
#include <stdlib.h>

void show(int n)
{
	int i;
	for(i = 0; i < sizeof(int) * 8; i++)
	{
		printf("%d", (n >> (sizeof(int) * 8 -1 - i) )& 0x01);
	}
	printf("\n");
}


int update_bits(int n, int m, int i, int j)
{
	int x;
	show(m);
	show(n);
	m = m << i;
	for(x = j + 1; x < sizeof(int) * 8; x++)
	{
		m &= ~((int)0x01<< x);
	}
	show(m);
	for(x = i; x <= j; x++)
	{
		n &= ~((int)0x01 << x);
		n |= m & (0x01 << x);
	}
	show(n);
	return 0;
}


int main()
{
	 update_bits(1024, 21, 2, 6);
	 update_bits(200, 21, 2, 6);

}