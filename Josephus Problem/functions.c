#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "header.h"
#include <time.h>
#include <string.h>

/// Read the names from "names.txt" randomly and store them in a circular doulby linked list
void readNames(struct node **head, int number)
{
    struct node *temp = *head;
    FILE *fp;
    int idx = 0, random = 0, number2 = 0;
    int compare;
    char name[25];
    char discard[25];
    srand(time(NULL));
    while (idx != number)
    {
        fp = fopen("names.txt", "r");
        if (fp == NULL)
        {
            printf("Cannot open file \n");
            exit(0);
        }

        random = rand() % 101;

        for (int i = 0; i < random; i++)
        {
            fgets(discard, sizeof(discard), fp);
        }

        fgets(name, sizeof(name), fp);
        while (temp != NULL)
        {
            compare = strcmp(temp->data.name, name);
            if (compare == 0)
            {
                number2++;
                break;
            }
            temp = temp->next;
        }
        if (number2 == 0)
        {
            insertLast(head, name);
            idx++;
        }
        number2 = 0;
        temp = *head;
        fclose(fp);
    }
}
/// Print the names from the linked list
void printList(struct node *head)
{
    struct node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("\n Index: %d. \t Name: %s", temp->data.id, temp->data.name);
        i++;
        temp = temp->next;
    }
}

/// Insert a new person at the end of the linked list
void insertLast(struct node **head, char name[20])
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->data.name, name);
    temp->next = NULL;
    temp->prev = NULL;
    if (*head == NULL)
    {
        temp->data.id = 1;
        *head = temp;
        return;
    }
    struct node *last = *head;
    while (last->next != NULL)
        last = last->next;
    temp->data.id = last->data.id + 1;
    last->next = temp;
    temp->prev = last;
    return;
}

// Compute the winner of The Josephus Problem.
 void josephus(struct node **head, int direction, int skip, int startPoint)
{
    struct node *temp = *head;
    struct node *temp2;
    struct node *temp3;

    int i = 1, o = 0, count = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = *head;
    (*head)->prev = temp;


    while (temp->next != temp)
    {
        i = 0;
        while (i != skip)
        {
            if (direction == 1)
            {
                temp = temp->next;
                i++;
            }
            else if (direction == 0)
            {
                while (o != 2)
                {
                    temp = temp->next;
                    o++;
                }
                temp = temp->prev;
                i++;
            }
            else
            {
                printf("Please enter either 1 or 0");
                exit(0);
            }
        }
        temp2 = temp->prev;
        temp3 = temp->next;
        temp2->next = temp3;
        temp3->prev = temp2;

        // print each iteration of Josephus Problem

        printf("\n \n Eliminated Index: %d \t %s  ", temp->data.id, temp->data.name);
        free(temp);
    }
    printf("\n \n The last person to be eliminated is the Winner");
    printf("\n \n The winner is: %s\t At Index %d ", temp->data.name, temp->data.id);
}
