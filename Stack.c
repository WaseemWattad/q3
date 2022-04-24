#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = (charNode*)malloc(sizeof(charNode));
	s->head->data = -1;
	s->head->next = NULL;
}

void destroyStack(Stack* s)
{
	if (s == NULL)
		return;
	destroyStack(s->head->next);
	free(s);
}

void push(Stack* s, char data)
{
	charNode* temp = s->head;
	while (temp->next != NULL) temp = temp->next;

	charNode* newstack = (charNode*)malloc(sizeof(charNode));
	newstack->data = data;
	newstack->next = NULL;
	temp->next = newstack;
}

char pop(Stack* s)
{
	if (s->head->next == NULL) {
		printf("Error: Pooping empty stack\n");
		return -1;
	}

	charNode* tmp = s->head;
	while (tmp->next->next != NULL) { tmp = tmp->next; }

	char payload = tmp->next->data;
	free(tmp->next);
	tmp->next = NULL;

	return payload;
}


int isEmptyStack(const Stack* s)
{
	if (s->head->next == NULL) return 1;
	return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	char* temp = (char*)sentence;
	Stack stack1; Stack* s1 = &stack1;
	initStack(s1);

	int count = 0;
	char string[100] = "";

	while (*temp != '\0') {

		if (*temp == '#') {
			temp++;

			int counter2 = 0;
			while (*temp != '#') {
				push(s1, *temp);
				temp++; counter2++;
			}
			for (int i = 0; i < counter2; i++) {
				string[count++] = pop(s1);
			}
			temp++;
		}
		else {
			string[count++] = *temp;
			temp++;
		}
	}
	string[count++] = '\0';
	printf("%s", string);
}

int isPalindrome(Stack* s)
{
	Stack ezer1 = *s, ezer2 = *s, rotated;

	initStack(&rotated);

	char bucket = 'a';
	while (bucket > 0) {
		bucket = pop(&ezer1);
		if (bucket == -1) break;
		push(&rotated, bucket);
		//push(&ezer1, bucket);
	}

	char bucket2 = 'a';
	while (bucket2 > 0) {

		bucket2 = pop(&rotated);

		if (pop(&ezer2) != bucket2) {
			return 0;
		}
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	Stack S2; initStack(&S2);
	Stack S3; initStack(&S3);
	int count = 0;
	if (isEmpty(*s) != 0)
	{
		//printf("Empty Stack");
		return;
	}
	while (s->head != NULL) {
		push(&S2, pop(s));
		count++;
	}
	while (S2.head != NULL)
		push(s, pop(&S2));

	if (n >= count)
		return;

	for (int i = 0; i < count - n; i++)
		push(&S2, pop(s));
	for (int i = 0; i < n; i++)
		push(&S2, pop(s));
	while (S2.head != NULL)
		push(s, pop(&S2));
	while (S2.head != NULL)
		push(s, pop(&S2));
	print(s);
}