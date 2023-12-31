#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "linked_list.h"
#include <malloc.h>


int main(int argc, char *argv[])
{
    int option;
    do
    {
        help();
        scanf("%d", &option);
        switch(option)
        {
            case 1: START = create_ll(START);
                if (START != NULL)
                    printf("list created succesfully\n");
                break;
            case 2: START = display(START);
                break;
            case 3: START = add_node_bg(START);
                break;
            case 4: START = add_node_end(START);
                break;
            case 5: START = insert_before(START);
                break;
            case 6: START = insert_after(START);
                break;
            case 7: START = delete_first(START);
                break;
            case 8: START = delete_selected(START);
                break;
            case 9: START = delete_last(START);
                break;
            case 10: START = ascending_node(START);
                break;
        }
    } while (option != 11);
    free(START);
    return 0;
}

void help(void)
{
    printf("\n*****linked list menu********\n\n");
    printf("\tPress 1 to create a list\n");
    printf("\tPress 2 to display all node\n");
    printf("\tPress 3 to add a node at top of list\n");
    printf("\tPress 4 to add node at last of list\n");
    printf("\tPress 5 to insert node before node looking for\n");
    printf("\tPress 6 to insert node after node looking for\n");
    printf("\tPress 7 to delete first node\n");
    printf("\tPress 8 to delete selected node\n");
    printf("\tPress 9 to delete last node\n");
    printf("\tPress 10 to change order of data node");
    printf("\tPress 11 to exit\n");
}

node_t *create_ll(node_t *start)
{
    node_t *newNode;
    node_t *ptr;
    int data;
    printf("enter data node or press -1 to end\n");
    scanf("%d", &data);
    while(data != -1)
    {
        newNode = (node_t*)calloc(1, sizeof(node_t));
        newNode->data = data;
        if (start == NULL) {
            newNode->next = NULL;
            start = newNode;
        } else {
            ptr = start;
            while(ptr->next != NULL)
            ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("enter an other data or end with typing -1\n");
        scanf("%d", &data);
    }
    return start;
}

node_t *display(node_t *start)
{
    node_t *ptr;
    ptr = start;
    int counter = 0;
    while(ptr != NULL) {
        printf("data for node %d is %d\n", counter, ptr->data);
        ptr = ptr->next;
        counter++;
    }
    return start;
}

node_t *add_node_bg(node_t *start)
{
    int data;
    printf("enter node data\n");
    scanf("%d",&data);
    node_t *newNode = (node_t*)calloc(1,sizeof(node_t));
    newNode->data = data;
    newNode->next = start;
    start = newNode;
    return start;
}
node_t *add_node_end(node_t *start)
{
    int data;
    printf("enter node data \n");
    scanf("%d", &data);
    node_t *newNode = (node_t*)calloc(1, sizeof(node_t));
    newNode->data = data;
    node_t *ptr = start;
    while (ptr->next != NULL)
    ptr = ptr->next;
    ptr->next = newNode;
    newNode->next = NULL;
    return start;
}

node_t *insert_before(node_t *start)
{
    int data;
    int search;
    printf("add data node looking for\t");
    scanf("%d", &search);
    printf("add data node\n");
    scanf("%d", &data);
    node_t *newNode = (node_t*)calloc(1,sizeof(node_t));
    node_t *ptr, *preptr;
    newNode->data = data;
    ptr = start;
    while(ptr->data != search) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return start;
}
node_t *insert_after(node_t *start)
{
    int data;
    int search;
    printf("add data node looking for\t");
    scanf("%d", &search);
    printf("add data node\n");
    scanf("%d", &data);
    node_t *newNode = (node_t*)calloc(1,sizeof(node_t));
    node_t *ptr, *preptr;
    newNode->data = data;
    ptr=start;
    while(ptr->data != search)
        ptr = ptr->next;   
    preptr = ptr->next;
    ptr->next = newNode;
    newNode->next = preptr;
    return start;
}

node_t *delete_first(node_t *start)
{
    node_t *ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

node_t *delete_selected(node_t *start)
{
    int data;
    node_t *ptr, *preptr;
    ptr = start;
    printf("enter data of node to delete\n");
    scanf("%d", &data);
    while(ptr->data != data) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
    
}
node_t *delete_last(node_t *start)
{
    node_t *ptr = start;
    node_t *preptr;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr=ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

node_t *ascending_node(node_t* start)
{
    node_t *ptr1, *ptr2;
    int tmp;
    ptr1 = start;
    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if( ptr1->data > ptr2->data) {
                tmp =ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = tmp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}