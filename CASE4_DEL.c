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
#include<ctype.h>
#include "MyLib.h"                              //contains prototypes of all functions used in the program.

struct address_t{
        int octet[4];
        char alias[11];
        char data[50];
        struct address_t *next;
};
extern struct address_t *head;

/************************ UDF Function to delete existing addresses in the List ***********************/
void del()
{
    char a_name[20];
    printf("Enter any Alias Name\n");
    fgets(a_name,20,stdin);
    if (a_name[0]!='\0')                        //Removing newline character from the buffer
    {
        size_t len = strlen(a_name);
        if (len > 0 && a_name[len-1] == '\n')
            {
                a_name[len-1] = '\0';
            }
    }
    int w,x,y,z,flag=0;
    struct address_t *temp;    // Creating a temporary pointer to the structure & pointing it to Head
    temp=head;
    int pos=0;
    char l_name[20];            //To get address from the linked list
    char c;
    while(temp!=NULL)
    {
        memset(l_name,'\0',sizeof(l_name));
        sscanf(temp->data, "%d.%d.%d.%d %s",&w, &x ,&y, &z, l_name);
        char arr1[50]="",arr2[50]="";
        for(int i = 0; i<(strlen(l_name)); i++) //to lowercase
        {
            arr1[i] = tolower(l_name[i]);
        }
        for(int j=0; j<(strlen(a_name)); j++) //to lowercase
        {
            arr2[j] = tolower(a_name[j]);
        }
        if(strcmp(arr1,arr2)==0)            //Checking the lowercase of aliases to make sure Alias names are not case sensitive.
        {
            flag=0;
            printf("\n%d.%d.%d.%d\n",w,x,y,z);
            printf("\nAre you sure you want to delete this record (Y|N)\n");
            scanf("%c",&c);
            if(c=='Y' || c=='y')            // checking for choice yes
            {
                delete(pos);
                disp();
                break;
            }
            else if(c=='N' || c=='n')           // checking for choice no
            {
                printf("\nYou have chosen not to delete this record..");
                return;
            }
            else                            // checking for other choice
            {
                printf("\nError!! Invalid choice..!!\n");
                return;
            }
        }
        else
        {                               // traversing through the linked list
            temp=temp->next;
            flag = 1;
            pos++;
        }
    }
    if(flag==1)
    {                                                       //prints error if there is no match
        printf("\nError!! Alias doesn'y exists..!!\n");
    }
}