//写程序将一个栈按升序排序。对这个栈是如何实现的，你不应该做任何特殊的假设。
// 程序中能用到的栈操作有：push | pop | peek | isEmpty。


#include <stdio.h>
#include <stdlib.h>

#define LEN 10

struct stack{
	int data[LEN];
	int cur;
};


int pop(struct stack *stack, int e)
{
	if(stack->cur == LEN)
		return -1;
	stack->data[stack->cur++] = e;

	return 0;
}


int push(struct stack *stack, int *e)
{
	if(stack->cur == 0)
		return -1;
	*e = stack->data[--stack->cur];
	stack->data[stack->cur] = 0;

	return 0;
}


void sort(struct stack *stack)
{
	int i, j;
	int temp;
	for(i = 0; i < stack->cur - 1; i++)
	{
		for(j = i + 1; j < stack->cur; j++)
		{
			if(stack->data[i] < stack->data[j])
			{
				temp = stack->data[i];
				stack->data[i] = stack->data[j];
				stack->data[j] = temp;
			}
		}
	}
}


void show(struct stack *stack)
{
	int i;
	for(i = 0; i < LEN; i++)
	{
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}

int main()
{
	int e;
	struct stack stack = {};
	pop(&stack, 2);sort(&stack);show(&stack);
	pop(&stack, 1);sort(&stack);show(&stack);
	pop(&stack, 7);sort(&stack);show(&stack);
	push(&stack, &e);sort(&stack);show(&stack);
	pop(&stack, 4);sort(&stack);show(&stack);
	push(&stack, &e);sort(&stack);show(&stack);
}