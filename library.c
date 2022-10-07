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
#include "MyLib.h"                                                  //contains declaration of all functions used in the program.

struct address_t                                                    //Declaration of the structure for the linked list.
{
        int octet[4];
        char alias[11];
        char data[50];
        struct address_t *next;
};
struct address_t *head=NULL;

void insert(char val[50])
{
    struct address_t *Node;                                          // Creating a new Node
    Node = (struct address_t *)malloc(sizeof(struct address_t));
    strcpy(Node->data,val);
    Node->next = NULL;

    if(head==NULL)                                                  // Checks if the list is empty
    {
        head = Node;                                                //If empty, then Node becomes the head
    }
    else
    {
        Node->next=head;                                            //Adds data to the Linked list in a stack fashion.
        head=Node;
    }
    return ;
}

void delete(int p)
{
    struct address_t *tmp = head;                                   // Creating a temporary variable pointing to head
    if(p==0)
    {
        printf("\nThe Node [%s] is Deleted Successfully!!..\n",tmp->data);
        head=head->next;
        tmp->next=NULL;
        free(tmp);                                                  // Deleting the Node if it points to head
    }
    else
    {
        for(int i=0;i<p-1;i++)                           // Looping until it reaches the "previous node" of the node to be deleted.
        {
            tmp=tmp->next;
        }

        // Now tmp points to the previous Node of the Node to be deleted
        struct address_t *del =tmp->next;                                   // "del" pointer points to the Node to be deleted
        tmp->next=tmp->next->next;                                          // Changing next pointer
        printf("\nThe Node %s is Deleted Successfully!!..\n",del->data);
        del->next=NULL;
        free(del);                                                          // freeing "del" to delete the Node.
    }
    printf("\nLinked List After Deletion is : \n");
    return ;
}