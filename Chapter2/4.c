//���������ɵ������ʾ������ÿ�����������е�һλ���֡����ֵĴ洢������ģ� 
//Ҳ����˵��λλ������ı�ͷ��дһ����ʹ����������Ӳ����ؽ�������Ҳ�������ʾ
//���ӣ�(3 -> 1 -> 5), (5 -> 9 -> 2)
//���룺8 -> 0 -> 8

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

int add(struct node *head1, struct node *head2, struct node **newhead)
{
	struct node *p, *q;
	struct node *newp, *newq;
	struct node *r;
	int c = 0;
	if(head1 == NULL && head2 == NULL)
		return -1;

	p = head1;
	q = head2;
	newp = NULL;	
	newq = NULL;

	while(p != NULL && q != NULL)
	{
		newp = (struct node *)malloc(sizeof(struct node));
		c = p->data + q->data + c;
		newp->data = c % 10;
		c /= 10;
		newp->next = NULL;

		p = p->next;
		q = q->next;
		
		if(newq == NULL)
		{
			*newhead =newp;
			newq = newp;
		}
		else
		{
			newq->next = newp;
			newq = newp;
		}
	}

	r = p == NULL ? q : p;
	
	while(r != NULL)
	{
		newp = (struct node *)malloc(sizeof(struct node));
		c = r->data +c;
		newp->data = c % 10;
		c /= 10;
		newp->next = NULL;

		r = r->next;
		
		if(newq == NULL)
		{
			*newhead =newp;
			newq = newp;
		}
		else
		{
			newq->next = newp;
			newq = newp;
		}
	}

	if(c == 1)
	{
		newp = (struct node *)malloc(sizeof(struct node));
		newp->data = c % 10;
		newp->next = NULL;

		newq->next = newp;
		newq = newp;
	}

	return 0;
}


int main()
{
	int a[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,6 ,5 ,4 ,3 ,8};
	int b[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,6 ,5 ,4 ,3 ,8};
	struct node *head1, *head2, *newhead;
	
	head1 = init(a, sizeof(a)/sizeof(int));
	head2 = init(b, sizeof(b)/sizeof(int));

	show(head1);
	show(head2);

	add(head1, head2, &newhead);
	show(newhead);
}
