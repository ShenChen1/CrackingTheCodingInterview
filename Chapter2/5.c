//给定一个循环链表，实现一个算法返回这个环的开始结点。
//定义：
//循环链表：链表中一个结点的指针指向先前已经出现的结点，导致链表中出现环。
//例子：
//输入：A -> B -> C -> D -> E -> C [结点C在之前已经出现过]
//输出：结点C


#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


struct node *init(int *a, int m, int n)
{
	int i;
	struct node *head;
	struct node *p;
	struct node *q;

	for(i = 0; i < m; i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a[i];
		p->next = NULL;
		
		if(i == 0)
		{
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}

	p = head;
	for(i = 0; i < n; i++)
	{
		p = p->next;
	}
	q->next = p;
	
	return head;
}

void show(struct node *head, int n)
{
	int i;
	struct node *p = head;
	for(i = 0; i < n; i++)
	{
		printf("%2d ", p->data);
		p = p->next;
	}
	printf("\n");
}

struct node *loopstart(struct node *head)
{
	struct node *p, *q;
	if(head == NULL)
		return NULL;
	p = head;
	q = head;

	while(q && q->next)
	{
		p = p->next;
		q = q->next->next; 
		if(p == q)
			break;
	}
	if(q == NULL || q->next == NULL) 
		return NULL;

	q = head;
	while(q != p)
	{
		p = p->next;
		q = q->next;
	}

	return p;
}


int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,0};
	struct node *head, *p;
	head = init(a, sizeof(a) / sizeof(a[0]), 3);
	show(head, sizeof(a) / sizeof(a[0]));
	p = loopstart(head);
	show(p, sizeof(a) / sizeof(a[0]) );
}
