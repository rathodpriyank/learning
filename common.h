

typedef struct node {
    int data;
    struct node *next;
} node_t;

void printList (node_t *head);
node_t *allocate(int data);
void prependNode (node_t **head, int data);
void appendNode(node_t **head, int data);
