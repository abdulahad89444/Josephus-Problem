#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include "node.h"

int main()
{
    int totalPeople, startPoint, skip, direction;
    struct node * head = NULL;

    printf("//////////////////////////////////////////////  Welcome to the Josephus Problem!  ////////////////////////////////////// ");

    while (1)
    {

        printf("\n \n Enter the total Number of People (Less than or equal to 100): ");
        scanf("%d", &totalPeople);

        if (totalPeople > 100 || totalPeople <= 0)
        {
            printf(" Enter a number less than 100 and greater than 0\n");
            continue;
        }
        else
        {
            printf("\n Enter the starting point: ");
            scanf("%d", &startPoint);
            fflush(stdin);
        }
        if (startPoint >= totalPeople || startPoint <= 0)
        {
            printf(" Please enter a starting point less than the total number of people. \n ");
            continue;
        }
        else
        {

            printf("\n Enter the direction, Clockwise (1) or Anticlockwise (0): ");
            scanf("%d", &direction);
            readNames(&head, totalPeople);

            if (direction > 1 || direction < 0)
            {
                printf("\n Please enter either 1 or 0. ");
                continue;
            }
            else
            {
                printf("\n How many people do you want to be skipped?: ");
                scanf("%d", &skip);
                if (skip >= totalPeople || skip < 0)
                {
                    printf(" Please enter a number less than the total people and greater than zero");
                    continue;
                }
                else
                {
                    printf("\n This is the initial List");
                    printList(head);

                    while(head->data.id != startPoint)
                        {
                            head = head->next;
                            head->prev=head->prev->next;
                        }

                    josephus(&head, direction, skip, startPoint);
                    exit(0);
                }
            }
        }
    }
    return 0;
}
