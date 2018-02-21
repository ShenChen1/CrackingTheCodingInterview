//ջ��������ӣ������ӵ���̫��ʱ���ͻ���б���¡
//���ˣ�����ʵ�������У���һ������ (ջ)������һ���ĸ߶�ʱ�����Ǿͻ�����һ�ѣ��ٴ�ͷ����
//ʵ�����ݽṹSetOfStacks ��ģ�����������
//SetOfStacks�ɼ���ջ��ɣ���ǰһջ��������ʱ����Ҫ����һ���µ�ջ ��������ݡ�
//SetOfStacks.push()��SetOfStacks.pop()����ΪӦ����ֻ��һ��ջʱ ���ֵ�һ����
//��һ���أ�
//ʵ�ֺ���popAt(int index)��ָ������ջ�Ͻ���pop������


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYNUM 3
struct stack{
	int curidx;//��ǰ�±�
	int array[ARRAYNUM];//ջ
	struct stack *next;
};

struct info{
	int curnum;//��ǰջ
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
		if(p == info.head)//û�����ݿ���ȡ
			return -1;
		free(p);//�ͷſ�ջ
		info.curnum--;
		p = info.head;//�����ҵ�ջ
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
	for(i = 0; i < num- 1; i++)//�ҵ�ջ
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