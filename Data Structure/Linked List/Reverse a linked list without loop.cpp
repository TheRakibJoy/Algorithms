/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* ret = NULL;
    
    void Recursive(ListNode* curr,ListNode* last)
    {
        if(curr->next != NULL)
            Recursive(curr->next , curr);
        curr->next = last;
        if(ret == NULL)
            ret = curr;
    }
    
    void Iterative(ListNode* curr,ListNode* last)
    {
        while(curr->next != NULL){
            ListNode* tempcurr = curr;
            
            curr = curr->next;
            
            tempcurr->next = last;
            last = tempcurr;
        }
        curr->next = last;
        
        ret = curr;
    }
    
    ListNode* reverseList(ListNode* head) {
        ret = NULL;
        if(head == NULL)
            return head;
        
        ListNode* last = NULL;
        
        //Recursive(head , last);
        
        Iterative(head , last);
        
        return ret;
    }
};
