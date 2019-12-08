#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node{
    int data;
    Node *next;
    Node *prev;
};
Node *head,*tail;
Node *CreateNode(int item,Node *prev,Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error! Could not create a new node\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}
void RemoveNode(Node *root,Node *last,Node *node)
{
    if(node == root){
        head = node->next;
        free(node);
    }
    else{
         Node *currNode = node;
         Node *prevNode = node->prev;
         Node *nextNode = node->next;
         prevNode->next = nextNode;
         if(nextNode != NULL)
            nextNode->prev = prevNode;
         free(currNode);
    }
}
void Prepend(Node *root,Node *last,int item)    /** Add node as starting node **/
{
    Node *newNode = CreateNode(item,NULL,root);
    root->prev = newNode;
    head = newNode;
}
void Append(Node *root,Node *last,int item)     /** Add node as ending node **/
{
    Node *newNode;
    if(root == NULL){       /** IF the list is empty,then the new node will be the head & tail **/
        newNode = CreateNode(item , NULL , NULL);
        head = newNode;
        tail = newNode;
    }
    else{
        newNode = CreateNode(item , last , NULL);
        last->next = newNode;
        tail = newNode;
    }
}
void Insert(Node *node , int item)  /** Add node not as starting nor as ending **/
{
    Node *newNode = CreateNode(item , node , node->next);
    node->next->prev = newNode;
    node->next = newNode;
}
void ForwardPrint(Node *root)
{
    printf("Printing the list forward:\n");
    Node *currNode = root;
    while(currNode != NULL){
        cout<<currNode->data<<endl;
        currNode = currNode->next;
    }
}
void BackwardPrint(Node *last)
{
    printf("Printing the list backward:\n");
    Node *currNode = last;
    while(currNode != NULL){
        cout<<currNode->data<<endl;
        currNode = currNode->prev;
    }
}

int main()
{
    head = CreateNode(20 , NULL , NULL);
    tail = head;
    Prepend(head , tail , 10);
    Append(head , tail , 40);
    Insert(head->next , 30);
    ForwardPrint(head);
    BackwardPrint(tail);
    return 0;
}
