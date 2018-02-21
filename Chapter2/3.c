//实现一个算法来删除单链表中间的一个结点，只给出指向那个结点的指针。

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void swap(int *a, int *b)
{
    	int t;
	t = *a;
    	*a = *b;
    	*b = t;
}

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

int  removenode(struct node *c)
{
	struct node *p;
	
	if(c == NULL)
		return -1;
	if(c->next == NULL)
		return -2;
	
	p = c->next;
	swap(&p->data, &c->data);

	c->next = p->next;
	free(p);

	return 0;
}


int main()
{
	int a[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,6 ,5 ,4 ,3 ,8,1};
	struct node *head;
	
	head = init(a, sizeof(a)/sizeof(int));

	show(head);
	printf("%d\n", removenode(head->next->next->next));
	show(head);
}