#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#define LINESIZE 300
void removeJunk(char *line);
int identifierCheck(char *id);
int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	int lineNum = 1;
	int insideComment = 0;
	char *line = malloc(LINESIZE);
  char *infileName = malloc(sizeof(argv[1]));
  char *outfileName = malloc(sizeof(argv[2]));

  infileName = argv[1];
  outfileName = argv[2];
  fin = fopen(infileName, "r");
  fout = fopen(outfileName, "w+");
  if(fout == NULL)
  {
    fprintf(stderr, "Could not open file. \n");
    exit(1);
  }
  if(fin == NULL)
	{
		fprintf(stderr, "Could not open file. \n");
    exit(1);
	}

	while(fgets(line, LINESIZE, fin))
	{
    //get rid of characters we don't need
		removeJunk(line);

		int len = strlen(line);
		int isComment = 0;
    int i;
		//need to add null terminator
		if (line[len-1] == '\n')
			line[len-1] = '\0';

		char *ch = line;
    //see if the line is a line comment
		for(i = 0; i < len-1; i++)
		{
			if(*(ch+i) == '/' && *(ch+i+1) == '/')
			{
				isComment = 1;
			}
		}
    //skip the line if it's a comment
		if(isComment == 1)
		{
      lineNum++;
			continue;
		}

		char *id = malloc(sizeof(line));
		strcpy(id, line);
		char *token;
    //tokenize string to seperate identifiers
		token = strtok(id, " ");
		while(token != NULL)
		{
			if(*token == '\n')
			{
        //move on to the next token
				token = strtok(NULL, " ");
				continue;
			}
			if(!identifierCheck(token))
			{
          //move on to the next token
					token = strtok(NULL, " ");
					continue;
			}
			else
			{
				struct node *temp = find(token);
        //if node does not exist, insert a new link
      	if(temp == NULL)
				{
					struct queue q;
					q.f = 0;
					q.r = -1;
					q.queue[0] = lineNum;
					q.size = 0;
					insertFirst(token, q);
				}
        //else we update the existing queue
				else
				{
						queueinsert(lineNum, &temp->lineNums);
				}
			}
			token = strtok(NULL, " ");
		}
		lineNum++;
	}
	printList();
  writeList(fout);
  free(line);
  fclose(fin);
}

//is the word an identifier?
int identifierCheck(char *id)
{
	//if the word starts with a digit, it cannot be an identifier
	if(isdigit(id[0]))
	{
		return 0;
	}
}

//remove characters that we want to ignore
void removeJunk(char *line)
{
  //list of characters to ignore
  char ignoreList[17] = {'.', '"', '<', '>', '#', '=', '+', '-', ';', '(', ')', '!', '|', '&', '*', '{', '}'};
  int ignoreLen = 17;
	int len = strlen(line);
	int i;
  //loop through each char in the line
	for(i = 0; i < len; i++)
	{
    //this checks if the '->' is used, and removes it
    if(line[i] == '-' && line[i+1] == '>')
    {
      //by setting the char to an empty space, the tokenizer will be able to split the words without any extra work
      line[i] = ' ';
      line[i+1] = ' ';
    }
    int j;
    //loop through each element in the ignoreList and see if the character should be ignored
    for(j = 0; j <= ignoreLen; j++)
    {
      if(line[i] == ignoreList[j])
      {
        line[i] = ' ';
      }
    }
	}
}
