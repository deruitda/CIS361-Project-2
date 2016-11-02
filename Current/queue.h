#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 100

struct queue
{
	int queue[QUEUESIZE];
	int size;
};

// Perform an insert operation.
void queueinsert(int oneelement, struct queue *q) {
		q->size++;
		q->queue[q->size] = oneelement;
}
