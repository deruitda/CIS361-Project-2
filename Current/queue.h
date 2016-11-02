#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 100

struct queue
{
	int queue[QUEUESIZE];
	//need to initialize to 0
	int  f;
	//need to initialize to -1
	int r;
	int size;
};

// Check if queue is full
int queuefull(struct queue q) {
	if(q.r == QUEUESIZE - 1) {
		return 1;
	}
	return 0;
}

// Check if the queue is empty
int queueempty(struct queue q) {
	if(q.f > q.r) {
		return 1;
	}
	return 0;
}

// Perform an insert operation.
void queueinsert(int oneelement, struct queue *q) {
		q->size++;
		q->queue[q->size] = oneelement;
}
