//*******************************************************************************************************
// Author   : Ramaswamy Iyappan
// Date     : March 13, 2202
// Subject  : This file is the main() file for the assignment2
// program  : main.c
// GMU ID   : G01348097
//*******************************************************************************************************


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "MyLib.h"                                  //contains prototypes of all functions used in the program.

struct address_t{                                   // Structure declaration
        int octet[4];
        char alias[11];
        char data[50];
        struct address_t *next;
};
extern struct address_t *head;

/************************ UDF Function to Display the Linked List ***********************/
void disp()
{
    int num=0;
    struct address_t *tmp=head;                   // Creating a temporary pointer to the structure & point it to start from Head
    while(tmp!=NULL)
    {
        num += 1;
        printf("\n->%s",tmp->data);
        tmp=tmp->next;                                  // Increasing the pointer position to traverse through the linked list
    }
    printf("\nNumber of nodes in the list: %d",num);    //Prints the number of nodes in the list
    if(head==NULL)
    {
        printf("\nThe list is empty!!!..\n");           //Prints if list is empty
    }
    return ;                                            // returns back to the switch() in main().
}
