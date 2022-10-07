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
#include "MyLib.h"                      //contains prototypes of all functions used in the program.

struct address_t{
        int octet[4];
        char alias[11];
        char data[50];
        struct address_t *next;
};
extern struct address_t *head;

/************************ UDF Function to save the file ***********************/
void Save()
{
    FILE *fPtr;
    char file_name[20];
    printf("\nPlease enter any File Name to save the List of Addresses: ");
    fgets(file_name,20,stdin);
    file_name[strcspn(file_name,"\n")]='\0';        //To remove newline character from the buffer
    fPtr = fopen(file_name, "w");
    struct address_t *tmp=head;     // Creating a temporary pointer to the structure & pointing it to Head
    while(tmp!=NULL)
    {
        fputs(tmp->data, fPtr);        // Writing the nodes into the file
        if(tmp->next!=NULL)            // To add newline after writing a node, to maintain one address/alias pair per line.
            fputs("\n",fPtr);
        tmp=tmp->next;                // Incrementing "tmp pointer" to point to the next node
    }
}