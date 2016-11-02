#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct node
{
   struct queue lineNums;
   char *identifier;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void writeList(FILE *fout)
{
  struct node *ptr = head;
  fputs("Identifiers:\r\n\r\n", fout);

  while(ptr != NULL)
  {
    int i = 0;
     fputs(ptr->identifier, fout);
     fputs(": ", fout);
     while(i <= ptr->lineNums.size)
     {
       char num[10];
       sprintf(num, "%d", ptr->lineNums.queue[i]);
       fputs(num, fout);
       fputs(", ", fout);
       i++;
     }
     ptr = ptr->next;
     fputs("\r\n", fout);
  }
  fclose(fout);
}
//display the list
void printList()
{
   struct node *ptr = head;
   printf("Identifiers:\n");

   //loop through all nodes
   while(ptr != NULL)
   {
      int i = 0;
      printf("%s: ", ptr->identifier);
      //print out line nums
      while(i <= ptr->lineNums.size)
      {
        printf("%d, ", ptr->lineNums.queue[i]);
        i++;
      }
      ptr = ptr->next;
      printf("\n");
   }
}

//insert link at the top of the list
void insertFirst(char *identifier, struct queue lineNums)
{
	if(head == NULL)
	{
		head = malloc(sizeof(struct node));
		head->identifier = identifier;
		head->lineNums = lineNums;
    //head->lineNums.size = -1;
	}
	else
	{
		//create a link
		struct node *link = (struct node*) malloc(sizeof(struct node));

		link->identifier = identifier;
		link->lineNums = lineNums;

		//point it to old first node
		link->next = head;

		//point first to new first node
		head = link;
	}
}

//find a link with given identifier
struct node* find(char *identifier){

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL)
   {
      return NULL;
   }

   //navigate through list
     while(strcmp(current->identifier, identifier) != 0){
      //if it is last node
      if(current->next == NULL){
         return NULL;
      }else {
         //go to next link
         current = current->next;
      }
   }

   //if lineNum found, return the current Link
   return current;
}
