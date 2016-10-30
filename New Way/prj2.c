#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#define LINESIZE 150
int main()
{
	//struct queue test;
	//test.f = 0;
	//test.r = -1;
	//test.queue[0] = 69;
	
	//insertFirst("hi", test);


	//struct node *tnode = find("hi");
	//printf("Queueeee val: %d\n", tnode->lineNums.queue[0]);
	
	FILE *fp;
	int lineNum = 0;
	char *line = malloc(LINESIZE);
	
	if((fp = fopen("test.c", "r")) == NULL)
	{
		fprintf(stderr, "Could not open file. \n");
	}
	ssize_t read;
	size_t len = 0;
	
	while((read = getline(&line, &len, fp)) != -1)
	{
		//printf("Line: %s\n", line);
		char *token;
		token = strtok(line, " ");
		while(token != NULL)
		{
			//if the token starts with a number, we know it's not an identifier
			if(isdigit(token[0]))
			{
				token = strtok(NULL, " ");
				continue;
			}
			else
			{
				token = strtok(token, "\n");
				printf("Token: %s\n", token);
				struct queue q;
				q.f = 0;
				q.r = -1;
				//for some reason the queueinsert function isn't working...
				q.queue[0] = lineNum;
				//queueinsert(lineNum, q);
				//printf("Queue Val: %d\n", q.queue[0]);
				insertFirst(token, q);
				struct node *test = find(token);
				
			}
			token = strtok(NULL, " ");
		}
		lineNum++;
	}
	printList();
}

