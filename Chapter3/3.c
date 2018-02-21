//Õ»¾ÍÏñµşÅÌ×Ó£¬µ±ÅÌ×ÓµşµÃÌ«¸ßÊ±£¬¾Í»áÇãĞ±µ¹ÏÂ¡
//£Òò´Ë£¬ÔÚÕæÊµµÄÊÀ½çÖĞ£¬µ±Ò»µşÅÌ×Ó (Õ»)³¬¹ıÁËÒ»¶¨µÄ¸ß¶ÈÊ±£¬ÎÒÃÇ¾Í»áÁíÆğÒ»¶Ñ£¬ÔÙ´ÓÍ·µşÆğ¡£
//ÊµÏÖÊı¾İ½á¹¹SetOfStacks À´Ä£ÄâÕâÖÖÇé¿ö¡£
//SetOfStacksÓÉ¼¸¸öÕ»×é³É£¬µ±Ç°Ò»Õ»³¬³öÈİÁ¿Ê±£¬ĞèÒª´´½¨Ò»¸öĞÂµÄÕ» À´´æ·ÅÊı¾İ¡£
//SetOfStacks.push()ºÍSetOfStacks.pop()µÄĞĞÎªÓ¦µ±ºÍÖ»ÓĞÒ»¸öÕ»Ê± ±íÏÖµÄÒ»Ñù¡£
//½øÒ»²½µØ£¬
//ÊµÏÖº¯ÊıpopAt(int index)ÔÚÖ¸¶¨µÄ×ÓÕ»ÉÏ½øĞĞpop²Ù×÷¡£


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYNUM 3
struct stack{
	int curidx;//µ±Ç°ÏÂ±ê
	int array[ARRAYNUM];//Õ»
	struct stack *next;
};

struct info{
	int curnum;//µ±Ç°Õ»
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
		if(p == info.head)//Ã»ÓĞÊı¾İ¿ÉÒÔÈ¡
			return -1;
		free(p);//ÊÍ·Å¿ÕÕ»
		info.curnum--;
		p = info.head;//ÖØĞÂÕÒµ½Õ»
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
	for(i = 0; i < num- 1; i++)//ÕÒµ½Õ»
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