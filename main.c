#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

Queue* readyQ() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	initQueue(q);

	for (int i = 0; i < 10; i++)
		enqueue(q, i);
	return q;
}
int main() {
	Queue* q = readyQ();

	rotateQueue(q);

	for (int i = 0; i < 10; i++)
		printf("%d\n", dequeue(q));
	return 0;
}




void archives() {
	/*char string[] = "remem#reb# th#si#";
	flipBetweenHashes(string);*/

	//Stack s1, *s = &s1;
//initStack(s);

//push(s, 'a');
//push(s, 'f');
//push(s, 'a');
////push(s, 'a');

////isPalindrome(s);

//printf("Is palindrome: %d\n", isPalindrome(s));
////printf("%c\n", pop(s));
////printf("%c\n", pop(s));
}