//��һ��N*N��������Ͻ�����һ�������ˣ���ֻ�������˶��������˶���
//��ô�� �������˶������½�һ���ж����ֿ��ܵ�·����
//��һ���أ�
//����������е�һЩ���ӣ��������ǲ���̤��ȥ�ġ����һ���㷨��������п��ܵ�·����

#include <stdio.h>
//path(i, j) = path(i-1, j) + path(i, j-1)
int path(int m,int n)
{
	if(m < 1 || n < 1)
		return -1;
	if(m == 1 || n ==1)
		return 1;

	return path(m - 1, n) + path(m, n - 1);
}

int main()
{
	printf("%d\n", path(2, 2));
	printf("%d\n", path(3, 3));
	printf("%d\n", path(4, 4));
}