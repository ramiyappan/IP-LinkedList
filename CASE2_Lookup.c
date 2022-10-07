//*******************************************************************************************************
// Author   : Ramaswamy Iyappan
// Date     : March 13, 2202
// Subject  : This file is the main() file for the assignment2
// program  : main.c
// GMU ID   : G01348097
//*******************************************************************************************************



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MyLib.h"                      //contains prototypes of all functions used in the program.

struct address_t
{
    int octet[4];
    char alias[11];
    char data[50];
    struct address_t *next;
};
extern struct address_t *head;

/************************ UDF Function to search for an Address ***********************/
void look()
{
    char A_name[20];
    printf("Enter the Alias Name for which the address is to be searched for: \n");
    fgets(A_name, 20, stdin);
    if (A_name[0] != '\0')                      // Replacing newline character with '\0'
    {
        size_t len = strlen(A_name);
        if (len > 0 && A_name[len - 1] == '\n')
        {
            A_name[len - 1] = '\0';
        }
    }
    struct address_t *temp = head; // Creating a temporary pointer to the structure & pointing it to Head
    int q, r, t, s;
    char t_name[20];
    int flag = 0; // temp points to head;
    while (temp != NULL)
    {
        memset(t_name, '\0', sizeof(t_name));
        char arr_1[50] = "", arr_2[50] = "";
        sscanf(temp->data, "%d.%d.%d.%d %s", &q, &r, &t, &s, t_name);
        for (int i = 0; i < (strlen(t_name)); i++) // to lowercase
        {
            arr_1[i] = tolower(t_name[i]);
        }
        for (int j = 0; j < (strlen(A_name)); j++)  // to lowercase
        {
            arr_2[j] = tolower(A_name[j]);
        }
        if (strcmp(arr_1, arr_2) == 0)              // Checks if any match is found in the linked list
        {
            flag = 1;
            printf("\n%d.%d.%d.%d\n", q, r, t, s);  //Prints the corresponding Address if it exists
            break;
        }
        temp = temp->next;                          // Traversing through the linked list
    }
    if (flag == 0)
    {
        printf("Record doesn't exist\n");           // Prints error if no match found
    }
}