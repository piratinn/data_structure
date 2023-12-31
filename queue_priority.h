
#include <time.h>
#define MAX_LENGTH_ARRAY    10

typedef struct node
{
    int data;
    int priority;
    int Ttime;
    struct node *next;
    struct node *prev;

}node_t;

node_t *START = NULL;
node_t *create_ll(node_t *start);
node_t *display(node_t *start);
node_t *add_node_bg(node_t *start);
node_t *add_node_end(node_t *start);
node_t *insert_before(node_t *start);
node_t *insert_after(node_t *start);
node_t *delete_first(node_t *start);
node_t *delete_selected(node_t *start);
node_t *delete_last(node_t *start);
node_t *ascending_node(node_t *start);
void help(void);
time_t get_rawtime(int year, int month, int day, int hours, int minutes);
void format_time(time_t rawTime);
node_t *insert(node_t* start);
node_t *delete(node_t* start);


