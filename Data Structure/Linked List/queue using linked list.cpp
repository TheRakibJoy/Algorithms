#include<iostream>
using namespace std;

typedef struct node Node;
struct node{
    int data;
    Node *next;
};
Node *head,*tail;
Node *CreateNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error! Could not create a new node\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}
void PUSHBACK(Node *root,Node *last,int item)
{
    Node *newNode = CreateNode(item);
    if(root == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        last->next = newNode;
        tail = newNode;
    }
}
void POPFRONT(Node *root)
{
    head = root->next;
    free(root);
}
void PrintQueue(Node *root)
{
    printf("Present queue look like:\n");
    while(root != NULL)
    {
        cout<<root->data<<endl;
        root = root->next;
    }
}

int main()
{
    PUSHBACK(head , tail , 5);
    PUSHBACK(head , tail , 10);
    PUSHBACK(head , tail , 15);
    PUSHBACK(head , tail , 20);
    PrintQueue(head);
    POPFRONT(head);
    PrintQueue(head);
    return 0;
}
