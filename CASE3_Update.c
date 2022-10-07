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
#include<ctype.h>                           // for using tolower() function
#include "MyLib.h"                          //contains prototypes of all functions used in the program.

struct address_t
{
    int octet[4];
    char alias[11];
    char data[50];
    struct address_t *next;
};
extern struct address_t *head;

/************************ UDF Function to Update Existing Addresses in the List ***********************/
void update()
{
    char aname[20];
    printf("Enter the alias\n");
    fgets(aname,20,stdin);
    if (aname[0]!='\0')                         // Replacing newline character with '\0'
    {
        size_t len = strlen(aname);
        if (len > 0 && aname[len-1] == '\n')
        {
            aname[len-1] = '\0';
        }
    }
    struct address_t *tmp=head;
    struct address_t *update;    // Creating a temporary pointer to the structure
    int q,r,t,s;
    char t_name[20];
    int flag=0;       // tmp points to head;
    while(tmp!=NULL)
    {
        memset(t_name,'\0',sizeof(t_name));
        sscanf(tmp->data, "%d.%d.%d.%d %s",&q, &r ,&t, &s, t_name);
        char arr_1[50]="",arr_2[50]="";
        for(int i = 0; i<(strlen(t_name)); i++) //to lowercase
        {
            arr_1[i] = tolower(t_name[i]);
        }
        for(int j=0; j<(strlen(aname)); j++) //to lowercase
        {
            arr_2[j] = tolower(aname[j]);
        }
        if(strcmp(arr_1,arr_2)==0)              // Checks if there is any match in the linked list
        {
            flag=1;
            printf("\n%d.%d.%d.%d\n",q,r,t,s);
            update=tmp;
            break;
        }
        tmp=tmp->next;
    }
    if(flag==0)                                 // If there is no match goes into the following code
    {
        printf("Record doesn't exist\n");
    }
    else
    {
        printf("Enter the address to be updated\n");
        char newadd[20];
        int q1,q2,q3,q4;
        blue:
        memset(newadd,'\0',sizeof(newadd));                     // Replacing newline character with '\0
        if (fgets(newadd, sizeof newadd, stdin) != NULL)
        {
            size_t len = strlen(newadd);
            if (len > 0 && newadd[len-1] == '\n')
            {
                newadd[--len] = '\0';
            }
        }
        sscanf(newadd,"%d.%d.%d.%d",&q1,&q2,&q3,&q4);
        if((q1>=0 && q1<256) && (q2>=0 && q2<256) && (q3>=0 && q3<256) && (q4>=0 && q4<256))    // Checking for valid input
        {
            int q,r,t,s;
            int flag1=0;
            char gname[20];
            while(tmp!=NULL)
            {
                sscanf(tmp->data, "%d.%d.%d.%d %s",&q, &r ,&t, &s, gname);
                if((q1==q && q2==r && q3==t && q4==s))               // checking if it already exists
                {
                    flag1=1;
                    printf("\nAddress already exists!!\n");
                    return;
                }
            tmp=tmp->next;
            }
            if(flag1==0)
            {
                char new[50]="";
                sprintf(new,"%d.%d.%d.%d %s",q1,q2,q3,q4,aname);
                strcpy(update->data,new);                           //adding the address to the linked list if it's valid
                printf("\nRecord updated!!");
                return;
            }
        }
        else
        {                                                           // prints error if invalid not in range
            printf("\nError!! Invalid range of Values..\n");
            printf("please Enter the address again: ");
            goto blue;
        }
    }
}