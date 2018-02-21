//实现一个栈，除了push和pop操作，还要实现min函数以返回栈中的最小值。 push，pop和min函数的时间复杂度都为O(1)。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 10

struct node{
	int data;
	int min;
};
struct stack{
	struct node array[MAXLINE];
	int cur;
	int min;
} ;
struct stack stack;

int stack_init()
{	
	memset(&stack, 0 ,sizeof(struct stack));
	stack.cur = 0;
	return 0;
}

int push(int val)
{
	struct node temp;

	if(stack.cur == MAXLINE)
		return -1;
	if(stack.cur == 0)
		stack.min = val;
	temp.data = val;
	temp.min = stack.min > val ? val : stack.min;

	stack.array[stack.cur] = temp;
	stack.cur++;
	stack.min = temp.min;

	return 0;
}

int pop(int *val)
{
	struct node temp;

	if(stack.cur == -1)
		return -1;

	--stack.cur;
	temp = stack.array[stack.cur];
	memset(&stack.array[stack.cur], 0 ,sizeof(struct node));
	*val = temp.data ;

	stack.min = temp.min;

	return 0;
}



void show()
{
	int i;
	printf("idx\tdata\tmin\n");
	for(i = 0; i< MAXLINE; i++)
	{
		printf("%d\t", i);
		printf("%d\t", stack.array[i].data);
		printf("%d\n", stack.array[i].min);
	}
}


int main()
{
	int val;
	stack_init();

	push(62);show();
	push(53);show();
	push(44);show();
	pop(&val);show();
	pop(&val);show();
	push(35);show();
	push(26);show();
	push(17);show();
	push(71);show();
	
}