//����A[1��n]����0��n����������������һ��������ʧ�ˡ�
//����������У� ���ǲ���ֱ��ͨ��A[i]ȡ�������еĵ�i������
//����A����ʾ�ɶ����ƣ� Ҳ����һ����0/1�ַ���������Ψһ��ʹ�õĲ���ֻ�С�ȡ��A[i]�еĵ�jλ����
//�������ֻ��Ҫ���ѳ���ʱ�䡣д�����ҳ���ʧ������������ʹ�����ʱ�临�Ӷ���O(n)��


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int missing(int a[], int n)
{
	int i, j;
	int temp;
	int *p;
	p = (int *)malloc(sizeof(int) * n);
	memset(p, 0, sizeof(int) * n);

	for(i = 0; i < n; i++)
	{
		for(j = sizeof(int)*8 - 1; j >=0; j--)
			temp = (temp << 1) | ((a[i]>>j) & 0x01);
		//printf("%d\n", temp);
		p[temp - 1] = 1;
	}
	for(i = 0; i < n; i++)
	{
		if(p[i] == 0)
			return i+1;
	}

	return -1;
}


int main()
{
	int a[] = {0, 1, 2, 3, 5};
	printf("%d\n", missing(a, 5));
}