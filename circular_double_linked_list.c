#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "circular_double_linked_list.h"
#include <malloc.h>


int main(int argc, char *argv[])
{
    int option;
    do
    {
        get_time();
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
            case 11: START = delete_list(START);
                break;
        }
    } while (option != 12);
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
    printf("\tPress 10 to change order of data node\n");
    printf("\tPress 11 to delete list\n");
    printf("\tPress 12 to exit\n");
}

void get_time(void)
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Current local time and day : %d:%d , %d/ %d/ %d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900 );
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
        if (start == NULL) {
            newNode = (node_t*)malloc(sizeof(node_t));
            newNode->data = data;
            newNode->prev = NULL;
            start = newNode;
            newNode->next = start;
            start = newNode;
        } else {
            newNode = (node_t*)malloc(sizeof(node_t));
            newNode->data = data;
            ptr = start;
            while(ptr->next != start)
                ptr = ptr->next;
            newNode->prev = ptr;
            ptr->next = newNode;
            newNode->next = start;
            start->prev = newNode;
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
    while(ptr->next != start) {
        printf("data for node %d is %d\n", counter, ptr->data);
        ptr = ptr->next;
        counter++;
    }
    counter++;
    printf("data for node %d is %d\n", counter, ptr->data);
    return start;
}

node_t *add_node_bg(node_t *start)
{
    int data;
    node_t *ptr;
    ptr = start;
    printf("enter node data\n");
    scanf("%d",&data);
    node_t *newNode = (node_t*)calloc(1,sizeof(node_t));
    while(ptr->next != start)
        ptr = ptr->next;
    newNode->data = data;
    newNode->prev = ptr;
    newNode->next = start;
    start->prev = newNode;
    ptr->next = newNode;
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
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = start;
    start->prev = newNode;
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
    node_t *ptr;
    newNode->data = data;
    ptr = start;
    while(ptr->data != search)
        ptr = ptr->next;
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    ptr->prev->next = newNode;
    ptr->prev = newNode;
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
    node_t *ptr;
    newNode->data = data;
    ptr=start;
    while(ptr->data != search)
        ptr = ptr->next;
    newNode->prev = ptr;
    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    return start;
}

node_t *delete_first(node_t *start)
{
    node_t *ptr = start;
    node_t *pstart = start;
    while (ptr->next != start)
        ptr = ptr->next;
    start = start->next;
    start->prev = ptr;
    ptr->next = start;
    free(pstart);
    return start;
}

node_t *delete_last(node_t *start)
{
    node_t *ptr = start;
    node_t *preptr;
    while(ptr->next != start){
        ptr=ptr->next;
    }
    ptr->prev->next = start;
    start->prev = ptr->prev;
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
    if(ptr->data == data) {
        start = delete_first(start);
        return start;
    }
    while(ptr->data != data)
        ptr = ptr->next;
    if(ptr->next == start) {
        start = delete_last(start);
        return start;
    }
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
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

node_t *delete_list(node_t* start)
{
    node_t *ptr;
    ptr = start;
    while(ptr->next != start)
        start = delete_last(start);
    free(ptr);
    return start;
}