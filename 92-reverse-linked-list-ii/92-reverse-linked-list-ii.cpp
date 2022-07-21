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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right)
            return head;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        temp->next = head;
        ListNode* prev;
        int pos =0;
        while(pos!=left){
            prev = temp;
            temp = temp->next;
            pos++;
        }
        ListNode* leftPrev = prev;
        
        while(pos!=right)
        {
            ListNode* temp2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp2;
            pos++;
            
        }
        ListNode* temp2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp2;
            leftPrev->next->next = temp;
            leftPrev->next = prev;
        return dummy->next;
        
    }
};