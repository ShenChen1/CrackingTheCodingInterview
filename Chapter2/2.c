//实现一个算法从一个单链表中返回倒数第n个元素。

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


struct node *init(int *a, int n)
{
	int i;
	struct node *head;
	struct node *p;
	struct node *q;

	for(i = 0; i < n; i++)
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

	return head;
}

void show(struct node *head)
{
	struct node *p = head;
	while(p != NULL)
	{
		printf("%2d ", p->data);
		p = p->next;
	}
	printf("\n");
}


int findNthToLast(struct node *head, int n, struct node **need)
{
	struct node *p, *q;
	int i;
	if(n < 1)
		return -1;

	if(head == NULL)
		return -2;

	p = head;
	q = head;

	for(i =0; i < n -1; i++)
	{
		if(q->next == NULL)
			return -3;
		q = q->next;
	}

	while(q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}

	*need = p;
	
	return 0;
}


int main()
{
	int a[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,6 ,5 ,4 ,3 ,8, 9};
	struct node *head, *need;
	
	head = init(a, sizeof(a)/sizeof(int));

	show(head);
	printf("%d\n", findNthToLast(head, 1, &need));
	printf("%d\n", need->data);
}