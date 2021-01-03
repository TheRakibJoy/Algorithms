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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        
        ListNode* mth = NULL;
        ListNode* nth = NULL;
        ListNode* prevmth = NULL;
        ListNode* nxtnth = NULL;
        ListNode* last = NULL;
        
        ListNode* curr = head;
        
        int now = 0;
        
        while(curr != NULL){
            now++;
            if(now == m-1)
                prevmth = curr;
            else if(now == m)
                mth = curr;
            else if(now == n)
                nth = curr;
            else if(now == n+1){
                nxtnth = curr;
                break;
            }
            
            if(now > m && now <= n){
                ListNode* tempcurr = curr;
                curr = curr->next;
                tempcurr->next = last;
                last = tempcurr;
            }
            else{
                last = curr;
                curr = curr->next;
            }
        }
        if(prevmth != NULL)
            prevmth->next = nth;
        
        mth->next = nxtnth;
        
        if(m > 1)
            return head;
        else
            return nth;
    }
};
