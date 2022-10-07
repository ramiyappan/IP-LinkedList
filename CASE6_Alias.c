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

struct address_t
{
    int octet[4];
    char alias[11];
    char data[50];
    struct address_t *next;
};
extern struct address_t *head;

/************************ UDF Function to search for an Alias ***********************/
void check_alias()
{
    int Ad1,Ad2;
    printf("\nEnter Two Address octets for which the corresponding Alias must be searched for..\n");
    up:                                 // Label to repromt
    printf("\nEnter Octet_1: ");
    if(scanf(" %d",&Ad1)==1)            // All if conditions to check for valid input
    {
        if(Ad1>=0 && Ad1<256)
        {
            up1:                        // Label to repromt
            printf("\nEnter Octet_2: ");
            if(scanf(" %d",&Ad2)==1)
            {
                if(!(Ad2>=0 && Ad2<256))
                {
                    printf("\nError!! Not valid..!! please enter btw 0-255..\n");
                    goto up1;
                }
            }
        }
        else                        // prints error if not in the valid range
        {
        printf("\nError!! Not valid..!! please enter btw 0-255..\n");
        goto up;
        }
    }
    struct address_t *temp=head;             // Creating a temporary pointer to the structure & pointing it to Head
    int a,b,c,d,flag=0;
    char arr[20];
    printf("\nAlias(s) having these octets in the address are: \n");
    while(temp!=NULL)
    {
        sscanf(temp->data,"%d.%d.%d.%d %s",&a,&b,&c,&d,arr);
        if(a==Ad1 && b==Ad2)                // Checking for corresponding addresses for
        {
            printf("\n%s",arr);
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("None\n");
        printf("\nNo records found for location: [%d.%d]\n",Ad1,Ad2);
    }
}