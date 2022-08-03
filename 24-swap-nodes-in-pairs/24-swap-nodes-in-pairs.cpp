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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head)
            return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* prev = head;
        if(!temp2)
            return head;
        head = temp2;
       
        while(temp1 && temp2){
            
            prev->next = temp2;
            prev = temp1;
            temp1->next = temp2->next;
            temp2->next = temp1;
            
            
            temp1 = temp1->next;
            if(temp1)
            temp2= temp1->next;
            
            
        }
        return head;
        
        
    }
};