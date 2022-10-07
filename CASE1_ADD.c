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
#include "MyLib.h"                                //contains prototypes of all functions used in the program.

struct address_t
{
    int octet[4];
    char alias[11];
    char data[50];
    struct address_t *next;
};
extern struct address_t *head;

/************************ UDF Function to Add addresses to the Linked list ***********************/
void add()
{
    char name[50];
    int a,b,c,d;
    printf("Enter Address in the format [0-255].[0-255].[0-255].[0-255] {AliasName}\n");
    char str[50];
    l:                              // Label to repromt the user
    memset(str,'\0',sizeof(str));   // CLearing the input buffer
    fgets(str,50,stdin);
    if (str[0]!='\0')               // Replacing the newline character with '\0'
    {
        size_t len = strlen(str);
        if (len > 0 && str[len-1] == '\n')
        {
            str[len-1] = '\0';
        }
    }
    if(sscanf(str, "%d.%d.%d.%d %s",&a, &b ,&c, &d, name)!=5)       // Checking for the number of valid inputs entered
    {
        printf("Error!! Invalid input!!");
        return;
    }
    else
    {
        if((a>=0 && a<256) && (b>=0 && b<256) && (c>=0 && c<256) && (d>=0 && d<256))    // checking if input is in valid range
        {
            struct address_t *temp=head;    // Creating a temporary pointer to the structure & pointing it to Head
            int flag=0;
            while(temp!=NULL)
            {
                int w,x,y,z;
                char temp1[50]="",temp2[50]="";
                char aliasname[50];
                memset(aliasname,'\0',sizeof(aliasname));
                sscanf(temp->data, "%d.%d.%d.%d %s",&w, &x ,&y, &z, aliasname);
                for(int i = 0; i<(strlen(aliasname)); i++)                      //to lowercase
                {
                    temp1[i] = tolower(aliasname[i]);
                }
                for(int j=0; j<(strlen(name)); j++)                             //to lowercase
                {
                    temp2[j] = tolower(name[j]);
                }
                if(strcmp(temp1,temp2)==0 || (a==w && b==x && c==y && d==z))    //Checking for any match in existing records
                {
                    flag=1;
                    printf("\nSame record found!!\n");
                    return;                             // exits the loop if any match found
                }
                else
                {
                    temp=temp->next;                // Traversing through the Linked list
                }
            }
            if(flag==0)
            {
                printf("\nRecord inserted!!..\n");
                insert(str);                        // Calls insert() method of the linked list to insert the Node
            }
        }
        else
        {                                               // Repromts the user if invalid
            printf("\nInvalid range of Values\n");
            printf("please enter address again:\n");
            goto l;
        }
    }
}