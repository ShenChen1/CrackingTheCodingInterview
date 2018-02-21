//编程解决汉诺塔问题，使用数据结构栈(偷个懒，如果不知道汉诺塔是什么，请自行Google)

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

struct stack{
	int data[LEN];
	int cur;
};

struct stack a = {{1, 2, 3}, 3};
struct stack b = {{0, 0, 0}, 0};
struct stack c = {{0, 0, 0}, 0};


void pop(struct stack *x, int e)
{
	x->data[x->cur++] = e;
}

void push(struct stack *x, int *e)
{
	*e = x->data[--x->cur];
	x->data[x->cur] = 0;
}

void show()
{
	int i;
	printf("show:\n");
	for(i = 0; i < LEN; i++)
	{
		printf("%2d ", a.data[i]);
	}
	printf("\n");
	for(i = 0; i < LEN; i++)
	{
		printf("%2d ", b.data[i]);
	}
	printf("\n");
	for(i = 0; i < LEN; i++)
	{
		printf("%2d ", c.data[i]);
	}
	printf("\n");
}

//将n个圆盘从柱子src移动到柱子dst，其中可以借助柱子bri。
void hanoi(int n, struct stack *src, struct stack *bri, struct stack *dst)
{
	int temp;
	if(n == 1)
	{
		push(src, &temp);
		pop(dst, temp);
		show();
	}
	else
	{
		hanoi(n - 1, src, dst, bri);
		push(src, &temp);
		pop(dst, temp);
		show();
		hanoi(n - 1, bri, src, dst);
	}
	
}


int main()
{

	hanoi(LEN, &a, &b, &c);

}
