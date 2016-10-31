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

//display the list
void printList()
{
   struct node *ptr = head;
   printf("\n[ ");

   //start from the beginning
   while(ptr != NULL)
{        
      printf("(%s,%d) ",ptr->identifier,ptr->lineNums.queue[0]);
      ptr = ptr->next;
   }

   printf(" ]\n");
}

//insert link at the first location
void insertFirst(char *identifier, struct queue lineNums)
{
	if(head == NULL)
	{
		head = malloc(sizeof(struct node));
		head->identifier = identifier;
		head->lineNums = lineNums;
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

//delete first item
struct node* deleteFirst()
{

   //save reference to first link
   struct node *tempLink = head;

   //mark next to first link as first 
   head = head->next;

   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty()
{
   return head == NULL;
}

int length()
{
   int length = 0;
   struct node *current;

   for(current = head; current != NULL; current = current->next)
{
      length++;
   }

   return length;
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
   while((current->identifier) != identifier){

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

//delete a link with given identifier
struct node* delete(char *identifier){

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;

   //if list is empty
   if(head == NULL){
      return NULL;
   }

   //navigate through list
   while(current->identifier != identifier){

      //if it is last node
      if(current->next == NULL){
         return NULL;
      }else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;             
      }

   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   }else {
      //bypass the current link
      previous->next = current->next;
   }    

   return current;
}
