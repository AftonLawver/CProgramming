#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
}Node;

// function declaration
void display(struct Node *head);
void concatenateList(struct Node *h1, struct Node *h2);
int insertNode(struct Node *head, int index, int value);

int main() {

    // create the first linked list
    struct Node *prev, *head, *p;
    int n,i;
    printf ("number of elements:");
    scanf("%d",&n);
    head=NULL;
    for(i=0;i<n;i++)
    {
        p=malloc(sizeof(struct Node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            prev->next=p;
        prev=p;
    }
    printf("%s", "First list: \n");
    display(head);

    // create the second linked list
    struct Node *prev2, *head2, *p2;
    int m,j;
    printf ("number of elements:");
    scanf("%d",&m);
    head2=NULL;
    for(j=0;j<m;j++)
    {
        p2=malloc(sizeof(struct Node));
        scanf("%d",&p2->data);
        p2->next=NULL;
        if(head2==NULL)
            head2=p2;
        else
            prev2->next=p2;
        prev2=p2;
    }
    printf("%s", "Second list:\n");
    display(head2);

    // concatenate the two linked lists
    concatenateList(head, head2);
    printf("%s", "New first list:\n");
    display(head);
    printf("%s", "New second list (nothing should be changed):\n");
    display(head2);

    return 0;
}

// for testing purposes
void display(struct Node *node) {
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

// utility function to create a new node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// insert node into the linked list at a user-defined position
// will return 0 if successful and 1 if unsuccessful
int insertNode(struct Node *head, int index, int value) {

    return 0;

}


void concatenateList(struct Node *h1, struct Node *h2) {
    if (h1->next == NULL) {
        h1->next = h2;
    }
    else {
        concatenateList(h1->next, h2);
    }

}