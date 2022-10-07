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
#include "MyLib.h"                             //contains prototypes of all functions used in the program.

/************************************Structure Definition*************************************/
struct address_t
{
        int octet[4];                   //Declared structure as given in the Assignment Description
        char alias[11];
        char data[50];
        struct address_t *next;
};
/********************************************************************************************/

/******************************main() Function Starts Here************************************/
int main()
{
    FILE *fp;                                   // creating a file pointer 'fp' to read the input from.
    char c[100];                                //Array to read lines from the file
    fp = fopen("CS531_Inet", "r");              //Opening the input file in 'r' reading mode
    if (fp == NULL)
    {                                           //If file is empty, prints Error
        printf("Error in opening file !");
        return 0;
    }
    while(fgets(c,150,fp))
    {

        size_t len = strlen(c);
        if (len > 0 && c[len-1] == '\n')        // Replacing newline character with Null character
        {
            c[--len] = '\0';
        }
        insert(c);                              //Inserting contents of the file to the linked list
    }
    printf("\n");
    fclose(fp);                                //Closing the file
    int choice;
    do                          // Displaying the MAIN MENU
    {   printf("\n");
        printf("\n|-------------------------------------------------------|");
        printf("\n|                        MENU                           |");
        printf("\n|-------------------------------------------------------|");
        printf("\n|                                                       |");
        printf("\n|     [1.]          Add Address                         |");
        printf("\n|     [2.]          Look Up Address                     |");
        printf("\n|     [3.]          Update Address                      |");
        printf("\n|     [4.]          Delete Address                      |");
        printf("\n|     [5.]          Display List                        |");
        printf("\n|     [6.]          Display Aliases For Location        |");
        printf("\n|     [7.]          Save To File                        |");
        printf("\n|     [8.]          Exit                                |");
        printf("\n|                                                       |");
        printf("\n|-------------------------------------------------------|");
        printf("\n\n");
        printf("Enter your choice: ");
        start:
        if(scanf(" %d",&choice)==1)        // To remove newline character from the buffer
        {
            int f=getchar();
            if(f==0)
            {
                printf(" ");
            }
        }
        switch(choice)                      // Switch function to call functions based on the user choice
        {
            case 1:
            {
                add();                     // Calls the function add() to add addresses to the list
                break;
            }
            case 2:
            {
                look();                    // Calls the function look() to check for an address in the list
                break;
            }
            case 3:
            {
                update();                  // Calls the function update() to update existing addresses in the list
                break;
            }
            case 4:
            {
                del();                     // Calls the function del() to delete an existing address
                break;
            }
            case 5:
            {
                disp();                    // Calls the function disp() to display the Linked list
                break;
            }
            case 6:
            {
                check_alias();             // Calls the check_alias() function to search for an existing address
                break;
            }
            case 7:
            {
                Save();                    // Calls the Save() function to save the Linked list to a File
                break;
            }
            case 8:
            {
                exit_this();               // Calls exit_this() function to Terminate the program
                break;
            }
        }
    }while(choice>0 && choice<9);          // Does when choice is within the range of options

    if((choice>0 && choice<9)==0)         // To print Error message for invalid input & reprompt the user
    {
        printf("\nInvalid Choice..");
        printf("\nPlease enter any valid choice(only from the available options)");
        printf("\n                              [OR]                             ");
        printf("\nPress 8 if you want to exit!: ");
        goto start;
    }

    return 0;
}
/********************************** main() Function Ends Here ************************************/

