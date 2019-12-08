#include<iostream>
using namespace std;

typedef struct node Node;
struct node{
    int data;
    Node *next;
};
Node *head;

Node *CreateNode(int item , Node *next)
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
void PopUP(Node *root)
{
    head = root->next;
    free(root);
}
void PushUP(int item , Node *root)
{
    Node *newNode = CreateNode(item , root);
    head = newNode;
}
void PrintStack(Node *root)
{
    printf("Present Stack Look Like:\n");
    while(root != NULL){
        cout<<root->data<<endl;
        root = root->next;
    }
}
int main()
{
    PushUP(20 , head);
    PushUP(15 , head);
    PushUP(10 , head);
    PushUP(5 , head);
    PrintStack(head);
    PopUP(head);
    PrintStack(head);
    return 0;
}
