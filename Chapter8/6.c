//ʵ��ͼ��������еġ���䡱����������һ������(���Բ�����)��
//һ�����ӵ��һ������ɫ�� ����������ֱ�������������ı߽�(�߽�������������ɫ����һ���������)

#include <stdio.h>
#include <stdlib.h>


int paint_fill(char *screen, int m, int n, int x, int y, char c)
{
	if(x > m -1 || y > n -1 || x < 0 || y < 0 || m < 0 || n <0)
		return -1;
	if(*(screen + x*n + y) == '1')
		return 1;
	else
	{
		if(*(screen + x*n + y) == c)
			return 0;
		*(screen + x*n + y) = c;
		paint_fill(screen, m, n, x + 1, y, c);
		paint_fill(screen, m, n, x - 1, y, c);
		paint_fill(screen, m, n, x, y + 1, c);
		paint_fill(screen, m, n, x, y - 1, c);
	}

	return 0;
}


void show(char *screen, int m, int n)
{
	int i, j;

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%c", *(screen + i*n + j));
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{

	char a[5][4] = {
		{'1', '1', '1', '1'}, 
		{'1', '0', '1', '1'},
		{'1', '0', '0', '1'},
		{'1', '0', '0', '1'},
		{'1', '1', '1', '1'},
	};

	show((char *)a, 5, 4);
	paint_fill((char *)a, 5, 4, 1, 1, '5');
	show((char *)a, 5, 4);

}