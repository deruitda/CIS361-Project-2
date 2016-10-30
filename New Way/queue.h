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

// Show queue content
int queueshow(struct queue q) {
	int i;
	if(queueempty(q)) {
		printf(" \n The queue is empty\n");
	} else {
		printf("Start->");
		for(i=q.f; i<=q.r; i++) {
			printf("%d ", q.queue[i]);
		}
		printf("<-End");
	}
	return 0;
}

// Perform an insert operation.
int queueinsert(int oneelement, struct queue q) {
	if( queuefull(q)) { 
		printf("\n\n Overflow!!!!\n\n");
	} else {
		++q.r;
		q.queue[q.r] = oneelement;
	}
	return 0;
}

// Perform a delete operation
int queuedelete(struct queue q) {
	int elem;
	if(queueempty(q)) {
		printf(" \n The queue is empty\n");
		return(-1);
	} else {
		elem=q.queue[q.f];
		q.f=q.f+1;
		return(elem);
	}
}