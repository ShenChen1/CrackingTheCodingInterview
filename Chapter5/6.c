//д���򽻻�һ�����������Ʊ�ʾ�е�����λ��ż��λ���þ������ٵĴ���ʵ�֡� 
//(���磬��0λ�͵�1λ��������2λ�͵�3λ������)

#include <stdio.h>
//5������ȡ��λ��A������ȡżλ
int swap_bits(int x)
{
	return ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
}

int show(int x)
{
	int i;
	for(i = 0; i < sizeof(int) * 8; i++)
	{
		printf("%d", x >> (sizeof(int)*8 - 1 - i) & 0x01);
	}
	printf("\n");
}

int main()
{
	int temp;
	temp = swap_bits(234);show(234);
	printf("%d\n", temp);show(temp);

}