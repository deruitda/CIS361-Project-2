#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#define LINESIZE 300
int main()
{
	struct queue test, testB, testC;
	test.f = 0;
	test.r = -1;
	test.queue[0] = 69;

	testB.f = 0;
	testB.r = -1;
	testB.queue[0] = 89;

	testC.f = 0;
	testC.r = -1;
	testC.queue[0] = 99;

	insertFirst("hi", test);
	insertFirst("#include", testB);
	insertFirst("h", testC);
	//printList();

	struct node *tnode = find("hi");

	FILE *fp;
	int lineNum = 0;
	char *line = malloc(LINESIZE);

	if((fp = fopen("test.c", "r")) == NULL)
	{
		fprintf(stderr, "Could not open file. \n");
	}
	ssize_t read;
	size_t len = 0;

	while(fgets(line, LINESIZE, fp))
	{
		printf("Line: %s\n", line);
		struct queue test;
		test.f = 0;
		test.r = -1;
		test.queue[0] = lineNum;

		insertFirst(line, test);
		printList();
		lineNum++;
	}
	//
	printList();
	//while((read = getline(&line, &len, fp)) != -1)
	//{
	//	//printf("Line: %s\n", line);
	//	char *token;
	//	token = strtok(line, " ");
	//	while(token != NULL)
	//	{
	//		//if the token starts with a number, we know it's not an identifier
	//		if(isdigit(token[0]))
	//		{
	//			token = strtok(NULL, " ");
	//			continue;
	//		}
	//		else
	//		{
	//			token = strtok(token, "\n");
	//			printf("Token: %s\n", token);
	//			struct queue q;
	//			q.f = 0;
	//			q.r = -1;
	//			//for some reason the queueinsert function isn't working...
	//			q.queue[0] = lineNum;
	//			//queueinsert(lineNum, q);
	//			//printf("Queue Val: %d\n", q.queue[0]);
	//			insertFirst(token, q);
	//			struct node *test = find(token);
	//
	//		}
	//		token = strtok(NULL, " ");
	//	}
	//	lineNum++;
	//}
	//printList();
}
