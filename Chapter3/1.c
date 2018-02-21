//你如何只用一个数组实现三个栈？

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 10

struct node{
	int flag;
	int data;
	int prev;
};

struct stack{
	int cur;
	int top1;
	int top2;
	int top3;
	struct node array[MAXLINE];
};

struct stack stack;

int stack_init()
{	
	memset(&stack, 0 ,sizeof(struct stack));
	
	stack.cur = 0;
	stack.top1 = -1;
	stack.top2 = -1;
	stack.top3 = -1;

	return 0;
}

int push(int which, int val)
{
	int i;
	struct node temp;
	temp.flag = 1;
	temp.data = val;

	if(stack.cur == MAXLINE)
		return -1;
	
	if(which == 1)
	{
		if(stack.top1 == -1)//第一个元素
		{
			temp.prev = -1;
			stack.array[stack.cur] = temp;
			stack.top1 = stack.cur;			
		}
		else
		{
			temp.prev = stack.top1;
			stack.array[stack.cur] = temp;	
			stack.top1 = stack.cur;
		}	

	}

	if(which == 2)
	{
		if(stack.top2 == -1)//第一个元素
		{
			temp.prev = -1;
			stack.array[stack.cur] = temp;
			stack.top2 = stack.cur;			
		}
		else
		{
			temp.prev = stack.top2;
			stack.array[stack.cur] = temp;	
			stack.top2 = stack.cur;
		}	
	}

	if(which == 3)
	{
		if(stack.top3 == -1)//第一个元素
		{
			temp.prev = -1;
			stack.array[stack.cur] = temp;
			stack.top3 = stack.cur;			
		}
		else
		{
			temp.prev = stack.top3;
			stack.array[stack.cur] = temp;	
			stack.top3 = stack.cur;
		}	
	}
	//每次执行完push操作， cur要沿着数组依次向后查找，直到找到第一个空的空间，用它的索引更新cur
	for(i = stack.cur; i < MAXLINE; i++)
	{
		if(stack.array[i].flag == 0)
		{
			stack.cur = i;
			break;
		}
	}	
	
	return 0;
}

int pop(int which, int *val)
{
	struct node temp;
		
	if(which == 1)
	{
		if(stack.top1 == -1)
			return -1;
		stack.array[stack.top1].flag = 0;
		temp = stack.array[stack.top1];
		stack.array[stack.top1].data = 0;
		stack.array[stack.top1].prev= 0;
		//每次执行pop操作，检查该元素对应索引是否小于cur
		stack.cur = stack.cur >  stack.top1 ? stack.top1 : stack.cur;
		stack.top1 = temp.prev;	
	}

	if(which == 2)
	{
		if(stack.top2 == -1)
			return -1;
		stack.array[stack.top2].flag = 0;
		temp = stack.array[stack.top2];
		stack.array[stack.top2].data = 0;
		stack.array[stack.top2].prev= 0;
		//每次执行pop操作，检查该元素对应索引是否小于cur
		stack.cur = stack.cur >  stack.top2 ? stack.top2 : stack.cur;
		stack.top2 = temp.prev;
	}

	if(which == 3)
	{
		if(stack.top3 == -1)
			return -1;
		stack.array[stack.top3].flag = 0;
		temp = stack.array[stack.top3];
		stack.array[stack.top3].data = 0;
		stack.array[stack.top3].prev= 0;
		//每次执行pop操作，检查该元素对应索引是否小于cur
		stack.cur = stack.cur >  stack.top3 ? stack.top3 : stack.cur;
		stack.top3 = temp.prev;
	}

	*val = temp.data;

	return 0;
}

void show()
{
	int i;
	printf("idx\tflag\tdata\tprev\n");
	for(i = 0; i< MAXLINE; i++)
	{
		printf("%d\t", i);
		printf("%d\t", stack.array[i].flag);
		printf("%d\t", stack.array[i].data);
		printf("%d\n", stack.array[i].prev);
	}
}


int main()
{
	int val;
	stack_init();

	push(1, 1);show();
	push(2, 4);show();
	push(1, 2);show();
	push(2, 5);show();
	pop(1, &val);show();
	pop(1, &val);show();
	push(1, 3);show();
	push(2, 6);show();
	push(2, 7);show();

	
}