#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *next;
};
Node *CreateNode(int item,Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error! Could not create a new node\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = next;
    return newNode;
}
Node *RemoveNode(Node *head,Node *node)
{
    /** There will be two case when we want to remove a node. They r if the node is head & if the node is not head **/
    if(node == head){       /** If removable node is head **/
        head = node->next;
        free(node);
        return head;
    }
    /** Otherwise **/
    Node *currentNode = head;
    while(currentNode != NULL){
        if(currentNode->next == node)
            break;
        currentNode = currentNode->next;    /** Current node is the previous node of removable node **/
    }
    if(currentNode == NULL)     /** IF the node we want to remove doesn't exist,then its previous node will be NULL **/
        return head;

    currentNode->next = node->next;     /** Removing desired node **/
    free(node);
    return head;
}
Node *prepend(Node *head,int item)  /** Add node as starting node **/
{
    Node *newNode = CreateNode(item , head);
    Node *newHead = newNode;
    return newHead;
}
Node *append(Node *head,int item)   /** Add node as ending node **/
{
    Node *newNode = CreateNode(item , NULL);

    if(head == NULL)    /** If the linked list is empty now,then the new node will be the head of the list **/
        return newNode;

    Node *currentNode = head;

    while(currentNode->next != NULL){       /** Find the last node of the list & store it in currentNode **/
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    return head;
}
void Insert(Node *node , int item)  /** Add node not as starting node & nor as ending node **/
{
    /** Here,we add newNode after node **/
    Node *newNode = CreateNode(item,node->next);
    node->next = newNode;
}
void PrintList(Node *head)
{
    printf("Present List: \n");
    Node *currentNode = head;
    while(currentNode != NULL){
        cout<<currentNode->data<<endl;
        currentNode = currentNode->next;
    }
}
int main()
{
    Node *head = CreateNode(10 , NULL);
    head = prepend(head , 5);
    head = append(head , 20);

    PrintList(head);
    Insert(head->next , 17);
    PrintList(head);

    head = RemoveNode(head , head->next->next);
    PrintList(head);
    return 0;
}

