#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string key;
    string value;
    Node* pre;
    Node* nxt;

    Node(){
        pre = NULL;
        nxt = NULL;
    }
    Node(string _key,string _value){
        key = _key;
        value = _value;
        Node();
    }
};

struct DoublyList
{
    Node* head;
    Node* tail;

    DoublyList(){
        head = new Node();
        tail = new Node();

        head->nxt = tail;
        tail->pre = head;
    }
    void Erase(Node *curr){
        curr->pre->nxt = curr->nxt;
        curr->nxt->pre = curr->pre;
    }
    void InsertHead(Node *curr){    ///before insert, head -> n1 -> n2 ->tail
        Node* temp = head->nxt;     ///after insert,  head -> curr -> n1 -> n2 ->tail
        head->nxt = curr;
        curr->nxt = temp;
        temp->pre = curr;
        curr->pre = head;
    }
    string popTail(){           ///before pop,  head -> n1 -> n2 ->tail
        Node* last = tail->pre; ///after pop,   head -> n1 -> tail
        string key = last->key;
        last->pre->nxt = tail;
        tail->pre = last->pre;
        return key;
    }
};

class LRUCache
{
private:
    int capacity;
    map<string , Node*>cache;
    DoublyList *List;

public:
    LRUCache(int _capacity){
        capacity = _capacity;
        List = new DoublyList();
    }
    string get(string key){
        if(cache.find(key) == cache.end()){
            return "NOT FOUND";
        }

        Node *curr = cache[key];
        List->Erase(curr);
        List->InsertHead(curr);
        return curr->value;
    }
    void put(string key,string value){
        Node* newNode = new Node(key , value);

        if(cache.find(key) != cache.end()){ ///Found
            Node* curr = cache[key];
            curr->value = value;

            List->Erase(curr);
            List->InsertHead(curr);
        }
        else{
            cache[key] = newNode;
            List->InsertHead(newNode);

            if(cache.size() > capacity){
                cache.erase(List->popTail());
            }
        }
    }
};

int main()
{
    return 0;
}
