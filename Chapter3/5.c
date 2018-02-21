//使用两个栈实现一个队列MyQueue。

#include <stdio.h>
#include <stdlib.h>

#define LEN 10

struct stack{
	int data[LEN];
	int cur;
};

struct queue{
	struct stack in;
	struct stack out;
};


int enqueue(struct queue *queue, int e)
{
	if(queue == NULL)
		return -1;

	if(queue->in.cur == LEN)
		return -2;

	queue->in.data[queue->in.cur++] = e;
	return 0;
}

int dequeue(struct queue *queue, int *e)
{
	int temp;
	if(queue->in.cur == 0)
		return -1;
	while(queue->in.cur != 0)
	{
		temp = queue->in.data[--queue->in.cur];
		queue->in.data[queue->in.cur] = 0;
		queue->out.data[queue->out.cur++] = temp;
	}
	*e = queue->out.data[--queue->out.cur];
	queue->out.data[queue->out.cur] = 0;
	while(queue->out.cur != 0)
	{
		temp = queue->out.data[--queue->out.cur];
		queue->out.data[queue->out.cur] = 0;
		queue->in.data[queue->in.cur++] = temp;
	}

	return 0;
}

void show(struct queue *queue)
{
	int i;
	printf("in:  ");
	for(i = 0; i < LEN; i++)
	{
		printf("%d ", queue->in.data[i]);
	}
	printf("\nout: ");
	for(i = 0; i < LEN; i++)
	{
		printf("%d ", queue->out.data[i]);
	}
	printf("\n ");
}


int main()
{
	int i = 0;
	struct queue queue = {};
	for(i =0; i < 10; i++)
	{
		enqueue(&queue, i);
	}
	show(&queue);
	dequeue(&queue, &i);
	dequeue(&queue, &i);
	dequeue(&queue, &i);enqueue(&queue, 1);
	show(&queue);
	
}