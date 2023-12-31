#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "queue_priority.h"
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
            case 1: START = display(START);
                break;
            case 2: START = insert(START);  
                break;
            case 3: START = delete(START);
                break;
            }
    } while (option != 4);
    free(START);
    return 0;
}

void help(void)
{
    printf("\n*****linked list menu********\n\n");
    printf("\tPress 1 to display all node\n");
    printf("\tPress 2 to insert new node in Queue\n");
    printf("\tPress 3 to delete node\n");
    printf("\tPress 4 to exit\n");
}


node_t *display(node_t *start)
{
    node_t *ptr;
    ptr = start;
    int counter = 0;
    while(ptr != NULL) {
        format_time(ptr->Ttime);
        ptr = ptr->next;
        counter++;
    }
    return start;
}

node_t *insert(node_t* start)
{
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    node_t *ptr;
    time_t rawTime;
    int data, year, month, day, hours, minutes;
    printf("enter  year, month, day, hours, minute\n");
    scanf("%d%d%d%d%d", &year, &month, &day, &hours, &minutes);
    rawTime = get_rawtime(year, month, day, hours, minutes);
    newNode->Ttime = rawTime;
    if(start == NULL || rawTime < start->Ttime) {
        newNode->next = start;
        newNode->prev = NULL;
        if(start != NULL) {
        start->prev = newNode;
        start->next = NULL;
        }
        start = newNode;
    }
    else {
        ptr = start;
        while(ptr->next != NULL && ptr->next->Ttime < rawTime)
        ptr = ptr->next;
        newNode->prev = ptr;
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr->next->prev = newNode;
    }
    return start;
}

node_t *delete(node_t *start){
    node_t *ptr;
    if(start == NULL){
        printf("error delete node\n");
        return start;
    }
    else {
        ptr = start;
        if(start->next == NULL)
            free(start);
        else {
        start = start->next;
        start->prev = NULL;
        free(ptr);
        }
        return start;
    }
}

node_t *ascending_node(node_t* start)
{
    node_t *ptr1, *ptr2;
    int ttime;
    ptr1 = start;
    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if( ptr1->Ttime > ptr2->Ttime) {
                ttime =ptr2->Ttime;
                ptr2->Ttime = ptr1->Ttime;
                ptr1->Ttime = ttime;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}

time_t get_rawtime(int year, int month, int day, int hours, int minutes)
{
    struct tm givenTime = { 0 };
    givenTime.tm_year = year - 1900;
    givenTime.tm_mon = month - 1;
    givenTime.tm_mday = day;
    givenTime.tm_hour = hours;
    givenTime.tm_min = minutes;
    givenTime.tm_isdst = -1;

time_t timeConv = mktime(&givenTime);
if (timeConv == -1) {
  puts("Conversion failed.");
}

// Implementation dependent output
printf("time is %lld\n", (long long) timeConv);
return timeConv;
}

void format_time(time_t rawTime){
    struct tm * timeinfo;
    timeinfo = localtime(&rawTime);
    printf("[%d %d %d %d:%d:%d]", timeinfo->tm_mday,
            timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}