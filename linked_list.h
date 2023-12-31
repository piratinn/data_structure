
#define MAX_LENGTH_ARRAY    10

typedef struct node
{
    int data;
    struct node *next;

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


