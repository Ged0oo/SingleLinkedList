/*
 * SingleLinkedLis.h
 *
 * Created: 3 NOV 2022
 * Author : Mohamed Nagy
 */


#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H


 /************************************************************************/
 /*                   section : includes                                 */
 /************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "StdTypes.h"


 /************************************************************************/
 /*                   section: data type declaration                     */
 /************************************************************************/

typedef struct 
{
    uint32 NodeData;
    struct Node* NodeLink;
}ST_node_t;


/************************************************************************/
/*                   section: functions declarations                    */
/************************************************************************/

void Insert_Node_At_Beginning(ST_node_t** List);
void Insert_Node_At_End(ST_node_t** List);
void Insert_Node_After(ST_node_t* List);
void Delete_Node_At_Beginning(ST_node_t** List);
void Delete_Node(ST_node_t* List);
void Display_All_Nodes(ST_node_t* List);
uint32 Get_Length(ST_node_t* List);

#endif // _SINGLE_LINKED_LIST_H