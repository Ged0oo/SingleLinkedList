/*
 * main.c
 *
 * Created: 3 NOV 2022
 * Author : Mohamed Nagy
 */


#include "SingleLinkedList.h"

void main()
{
	struct Node* ListHead = NULL;

    uint8 UserChoice = 0;
    uint32 ListLength = 0;

    printf("-> Hello to Single Linked List \n");
    while (1)
    {
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch (UserChoice)
{
        case 1:
            Insert_Node_At_Beginning(&ListHead);
            break;

        case 2:
            Insert_Node_At_End(&ListHead);
            break;

        case 3:
            Insert_Node_After(ListHead);
            break;

        case 4:
            Delete_Node_At_Beginning(&ListHead);
            break;

        case 5:
            Delete_Node(ListHead);
            break;

        case 6:
            Display_All_Nodes(ListHead);
            break;

        case 7:
            ListLength = Get_Length(ListHead);
            printf("List Length : << %i >> Nodes\n", ListLength);
            break;

        case 8:
            printf("Quit from application \n");
            exit(1);
            break;

        default:
            printf("User Choice out of range !!\n");
            break;
        }
    }
}