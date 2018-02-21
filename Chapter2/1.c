//��һ��δ������������Ƴ��ظ�����
//��һ���أ����������ʹ����ʱ�Ļ��棬����ν��������⣿

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

void removedulicate(struct node *head)
{
	struct node *p, *q,*temp;
	p = head;
	
	while(p != NULL)
	{
		q = p;
		while(q->next!=NULL)
		{
			if(p->data == q->next->data)
			{
				temp = q->next;
				q->next = temp->next;
				free(temp);
			}
			if(q->next != NULL)//q�������һ�����
				q= q->next;
		}
		p = p->next;
	}

}


int main()
{
	int a[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,6 ,5 ,4 ,3 ,8, 1};
	struct node *head;
	
	head = init(a, sizeof(a)/sizeof(int));

	show(head);
	removedulicate(head);
	show(head);
}