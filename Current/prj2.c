#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#define LINESIZE 300
int main()
{
	FILE *fp;
	int lineNum = 1;
	int insideComment = 0;
	char *line = malloc(LINESIZE);

	if((fp = fopen("test.c", "r")) == NULL)
	{
		fprintf(stderr, "Could not open file. \n");
	}

	while(fgets(line, LINESIZE, fp))
	{
		int len = strlen(line);
		int isComment = 0;
		//need to add null terminator
		if (line[len-1] == '\n')
			line[len-1] = '\0';

		removeJunk(line);
		int i;
		char *ch = line;
		for(i = 0; i < len-1; i++)
		{
			if(*(ch+i) == '/' && *(ch+i+1) == '/')
			{
				isComment = 1;
			}
		}
		if(isComment == 1)
		{
			printf("Found a comment\n");
			continue;
		}

		//printf("Line: %s\n", line);
		char *id = malloc(sizeof(line));
		strcpy(id, line);
		char *token;
		token = strtok(id, " ");
		while(token != NULL)
		{
			printf("Token: %s\n", token);
			if(*token == '\n')
			{
				token = strtok(NULL, " ");
				continue;
			}
			if(!identifierCheck(token))
			{
					token = strtok(NULL, " ");
					lineNum++;
					continue;
			}
			else
			{
				struct node *temp = find(token);
				if(temp == NULL)
				{
					struct queue q;
					q.f = 0;
					q.r = -1;
					q.queue[0] = lineNum;
					q.size = 0;
					insertFirst(token, q);
				}
				else
				{
						queueinsert(lineNum, &temp->lineNums);
						//need to do this in queue function temp->qSize++;
						//printf("val: %d abd val2: %d\n", temp->lineNums.queue[0], temp->lineNums.queue[1]);
				}
			}
			token = strtok(NULL, " ");
		}
		lineNum++;
	}
	printList();
}

int identifierCheck(char *id)
{
	char *word = malloc(sizeof(id));
	strcpy(word, id);
	//if the word starts with a digit, it cannot be an identifier
	if(isdigit(word[0]) || word[0] == '{' || word[0] == '}')
	{
		return 0;
	}
}

void removeJunk(char *line)
{
	char *temp = malloc(strlen(line));
	memcpy(temp, line);

	int len = strlen(temp);
	int i;
	for(i = 0; i < len; i++)
	{
		if(temp[i] == '.')
		{
			printf("Found a dot\n");
		}
	}

}
