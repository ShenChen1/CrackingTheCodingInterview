//栈就像叠盘子，当盘子叠得太高时，就会倾斜倒下�
//Ｒ虼耍谡媸档氖澜缰校币坏套� (栈)超过了一定的高度时，我们就会另起一堆，再从头叠起。
//实现数据结构SetOfStacks 来模拟这种情况。
//SetOfStacks由几个栈组成，当前一栈超出容量时，需要创建一个新的栈 来存放数据。
//SetOfStacks.push()和SetOfStacks.pop()的行为应当和只有一个栈时 表现的一样。
//进一步地，
//实现函数popAt(int index)在指定的子栈上进行pop操作。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYNUM 3
struct stack{
	int curidx;//当前下标
	int array[ARRAYNUM];//栈
	struct stack *next;
};

struct info{
	int curnum;//当前栈
	struct stack *head;
};


struct info info;

struct stack *add_stack()
{
	struct stack *new;
	new = (struct stack *)malloc(sizeof(struct stack));
	memset(new->array, 0 ,ARRAYNUM);
	new->curidx = 0;
	new->next = NULL;
	return new;
}


int init_info()
{
	info.curnum = 1;
	info.head = add_stack();
}

int push(int val)
{
	int i;
	struct stack *p = info.head;
	if(info.head ==NULL)
		return -1;
	for(i = 0; i < info.curnum - 1; i++)
	{
		p = p->next;
	}
	p->array[p->curidx] = val;
	p->curidx++;
	if(p->curidx == ARRAYNUM)
	{
		p->next = add_stack();
		info.curnum++;
	}

	return 0;
}

int pop(int *val)
{
	int i;
	struct stack *p = info.head;
	if(info.head ==NULL)
		return -1;
	for(i = 0; i < info.curnum - 1; i++)
	{
		p = p->next;
	}
	if(p->curidx == 0)
	{
		if(p == info.head)//没有数据可以取
			return -1;
		free(p);//释放空栈
		info.curnum--;
		p = info.head;//重新找到栈
		for(i = 0; i < info.curnum - 1; i++)
		{
			p = p->next;
		}
		p->next = NULL;
	}
	p->curidx--;	
	*val = p->array[p->curidx];
	p->array[p->curidx] = 0;

	return 0;
}

int popat(int num, int *val)
{
	int i;
	struct stack *p = info.head;
	if(info.head ==NULL)
		return -1;
	if(num > info.curnum)
		return -2;
	for(i = 0; i < num- 1; i++)//找到栈
	{
		p = p->next;
	}

	if(p->curidx == 0)
		return -3;

	p->curidx--;	
	*val = p->array[p->curidx];
	p->array[p->curidx] = 0;

	return 0;
}

void show()
{
	int i, j;
	struct stack *p = info.head;
	for(i = 0; i < info.curnum; i++)
	{	
		printf("stack %d:", i);
		for(j = 0; j < ARRAYNUM ; j++)
		{
			printf("%2d ", p->array[j]);
		}
		printf("\t");
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int val;
	init_info();

	push(1);show();
	push(2);show();
	push(3);show();
	push(4);show();
	push(5);show();
	push(6);show();
	push(11);show();
	push(12);show();
	push(13);show();
	push(14);show();	
	pop(&val);show();
	pop(&val);show();
	pop(&val);show();
	pop(&val);show();
	push(15);show();
	push(16);show();
	popat(1, &val);show();
	popat(1, &val);show();
	popat(1, &val);show();
	popat(1, &val);show();

}