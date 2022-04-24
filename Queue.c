#include "Queue.h"
#include "Stack.h"
#include <stdlib.h>
/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q) {

	q->head = (intNode*)malloc(sizeof(intNode));
	q->head->next = NULL;
	q->head->data = 0;

	q->tail = q->head;
}

void destroyQueue(Queue* q)
{
	if (q == NULL)
		return;
	destroyQueue(q->head->next);
	free(q);
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* temp = q->head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	intNode* newq = (intNode*)malloc(sizeof(intNode));
	newq->data = data;
	newq->next = NULL;

	temp->next = newq;

	if (isEmptyQueue(q)) q->tail = newq;

}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q)) return -1; // code -10 : cannot DQ empty Q

	intNode* temp = q->head->next;
	int payload = q->head->next->data;

	q->head->next = q->head->next->next;
	free(temp);
	return payload;
}

int isEmptyQueue(const Queue* q)
{
	//if (q->head == q->tail) return 1;
	if (q->head->next == NULL) return 1;
	return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	Stack tempstack; Stack* st = &tempstack;
	initStack(st);

	int temp = dequeue(q), count = 0;
	while (temp != -1) {
		push(st, temp);
		count++;
		temp = dequeue(q);
	}

	for (count; count > 0; count--) {
		enqueue(q, pop(st));
	}
}

void cutAndReplace(Queue* q)
{
	Queue q1; initQueue(&q1);
	Queue q2; initQueue(&q2);
	int count = 0;
	int res = 0;
	if (isEmpty(q)) {
		//printf("Empty queue");
		return;
	}
	while (!isEmpty(q)) {
		count++;
		res += q->head->data;
		enqueue(&q2, dequeue(q));
	}
	if (count % 2 != 0) {
		res = res / count;
		enqueue(&q2, res);
		count++;
		for (int i = 0; i < count / 2; i++)
			enqueue(&q1, dequeue(&q2));
		reverse(&q2);
		for (int i = 0; i < count / 2; i++)
			enqueue(&q2, dequeue(&q1));
	}
	else {
		for (int i = 0; i < count / 2; i++)
			enqueue(&q1, dequeue(&q2));
		reverse(&q2);
		for (int i = 0; i < count / 2; i++)
			enqueue(&q2, dequeue(&q1));
	}
	print(&q2);
}

void sortKidsFirst(Queue* q)
{
	Queue q1; initQueue(&q1);
	Queue q2; initQueue(&q2);
	int data, temp, counter = 0;
	if (isEmpty(q)) {
		//printf("Empty queue");
		return;
	}
	for (int i = 0; !(isEmpty(q) && isEmpty(&q1)); i++) {
		if (isEmpty(q))
			enqueue(&q2, minandmax(&q1, q));
		else
			enqueue(&q2, min_max(q, &q1));
	}
	while (!isEmpty(&q2))
		enqueue(q, dequeue(&q2));
	print(q);
}