#include<iostream>
using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *lft;
    Node *rgt;
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
    newNode->lft = NULL;
    newNode->rgt = NULL;
    return newNode;
}
void PUSHBACK(Node *last,int item)
{
    Node *newNode = CreateNode(item);
    if(last == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->lft = last;
        last->rgt = newNode;
        tail = newNode;
    }
}
void PUSHFRONT(Node *root,int item)
{
    Node *newNode = CreateNode(item);
    if(root == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->rgt = root;
        root->lft = newNode;
        head = newNode;
    }
}
void POPBACK(Node *last)
{
    Node *prev = last->lft;
    prev->rgt = NULL;
    free(last);
    tail = prev;
}
void POPFRONT(Node *root)
{
    Node *nxt = root->rgt;
    nxt->lft = NULL;
    free(root);
    head = nxt;
}
void PrintDQForward(Node *root)
{
    printf("Printing deque from left:\n");
    while(root != NULL){
        cout<<root->data<<endl;
        root = root->rgt;
    }
}
void PrintDQBackward(Node *last)
{
    printf("Printing deque from right:\n");
    while(last != NULL){
        cout<<last->data<<endl;
        last = last->lft;
    }
}

int main()
{
    PUSHFRONT(head , 7);
    PUSHBACK(tail , 5);
    PUSHBACK(tail , 10);
    PUSHBACK(tail , 15);
    PUSHFRONT(head , 1);
    PUSHBACK(tail , 20);
    PrintDQForward(head);
    PrintDQBackward(tail);

    POPFRONT(head);
    POPBACK(tail);

    PrintDQForward(head);
    PrintDQBackward(tail);
    return 0;
}
