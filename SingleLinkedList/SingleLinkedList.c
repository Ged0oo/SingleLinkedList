/*
 * SingleLinkedLis.c
 *
 * Created: 3 NOV 2022
 * Author : Mohamed Nagy
 */


#include "SingleLinkedList.h"


 /**
   * @brief  Inserts a new node at the beggining of the list.
             Validate the case of temp head node
             and validate the case of empty linked list
   * @param  (List) pointer to linked list head structure.
   * @retval void ret.
   */
void Insert_Node_At_Beginning(ST_node_t** List)
{
    ST_node_t* TempNode = NULL;

    TempNode = (ST_node_t*)malloc(sizeof(ST_node_t));
    if (NULL != TempNode)
    {
        printf("Enter Node Data : ");
        scanf("%i", &TempNode->NodeData);

        /* Check if linked list is empty */
        if (NULL == *List)
        { /* Linked list is empty */
            TempNode->NodeLink = NULL;
            *List = TempNode;
        }
        else
        { /* Linked list is not empty */
            TempNode->NodeLink = *List;
            *List = TempNode;
        }
    }
    else 
    {
        /* Nothing */
    }
}



/**
  * @brief  Inserts a new node at the end of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Insert_Node_At_End(ST_node_t** List)
{
    ST_node_t* TempNode = NULL;
    ST_node_t* LastNode = NULL;

    TempNode = (ST_node_t*)malloc(sizeof(ST_node_t));
    if (NULL != TempNode) 
    {
        printf("Enter Node Data : ");
        scanf("%i", &TempNode->NodeData);
        TempNode->NodeLink = NULL;

        /* Check if linked list is empty */
        if (NULL == *List)
        { /* Linked list is empty */
            *List = TempNode;
        }
        else 
        { /* Linked list is not empty */
            LastNode = *List;
            while (LastNode->NodeLink != NULL) 
            {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }
    }
    else
    {
        /* Nothing */
    }
}



/**
  * @brief  Inserts a new node at specific index of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Insert_Node_After(ST_node_t* List)
{
    ST_node_t* TempNode = NULL;
    ST_node_t* NodeListCounter = NULL;
    uint32 NodePosition = 0;    /*  */
    uint32 ListLength = 0;      /*  */
    uint32 NodeCounter = 1;     /* Points to the first node */

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &NodePosition);

    ListLength = Get_Length(List);
    if (NodePosition > ListLength) 
    {
        printf("Invalid Node Position -> List has ( %i ) Nodes \n", ListLength);
    }
    else 
    {
        NodeListCounter = List;
        while (NodeCounter < NodePosition) 
        {
            NodeCounter++;
            NodeListCounter = NodeListCounter->NodeLink;
        } /* TempNode points to the node where we have to insert after it */
        TempNode = (struct Node*)malloc(sizeof(ST_node_t));
        if (NULL != TempNode) 
        {
            printf("Enter Node Data : ");
            scanf("%i", &TempNode->NodeData);
            /* Connect the right side connection */
            TempNode->NodeLink = NodeListCounter->NodeLink;
            /* Connect the Left side connection */
            NodeListCounter->NodeLink = TempNode;
        }
        else
        {
            /* Nothing */
        }
    }
}



/**
  * @brief  Deletes a node from the beggining of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Delete_Node_At_Beginning(ST_node_t** List)
{
    ST_node_t* TempNode = *List;
    uint32 ListLength = 0;      /*  */

    ListLength = Get_Length(*List);
    if (ListLength == 0) 
    {
        printf("List is Empty , nothing to be deleted !! \n");
    }
    else 
    {
        *List = TempNode->NodeLink;
        TempNode->NodeLink = NULL; /* TempNode is a free node */
        free(TempNode);
    }
}



/**
  * @brief  Deletes a node from specific index of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Delete_Node(ST_node_t* List)
{
    ST_node_t* NodeListCounter = List;
    ST_node_t* NextNode = List;
    uint32 NodePosition = 0;    /*  */
    uint32 ListLength = 0;      /*  */
    uint32 NodeCounter = 1;     /* Points to the first node */

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &NodePosition);
    ListLength = Get_Length(List);
    if ((NodePosition > ListLength) || (ListLength == 1))
    {
        printf("Please use Delete_Node_At_Beginning !! \n");
    }
    else
    {
        while (NodeCounter < (NodePosition - 1)) 
        {
            NodeCounter++;
            NodeListCounter = NodeListCounter->NodeLink;
        }
        NextNode = NodeListCounter->NodeLink;
        NodeListCounter->NodeLink = NextNode->NodeLink;
        free(NextNode);
    }
}



/**
  * @brief  Display all the nodes of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Display_All_Nodes(ST_node_t* List)
{
    ST_node_t* TempNode = List;

    printf("Node Values : ");
    if (NULL == TempNode)
    {
        printf("List is empty !! \n");
    }
    else
    {
        while (TempNode != NULL) 
        {
            printf("%i -> ", TempNode->NodeData);
            TempNode = TempNode->NodeLink;
        }
        if (NULL == TempNode) 
        {
            printf("NULL \n");
        }
    }
}



/**
  * @brief  Get number of nodes assoiated with the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval Number of nodes.
  */
uint32 Get_Length(ST_node_t* List)
{
    ST_node_t* TempNode = List;
    uint32 NodeCount = 0;

    while (TempNode != NULL) 
    {
        NodeCount++;
        TempNode = TempNode->NodeLink;
    }

    return NodeCount;
}