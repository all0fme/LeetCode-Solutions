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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* temp = head;
        if(!head || !head->next)
            return head;
        
        int len =0;
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        k = k%len;
        temp = head;
        if(k>0)
        {
             for(int i=1;i<len-k;i++)
        {
            temp = temp->next;
        }
        ListNode* start = temp->next;
        ListNode* temp2 = start;
        while(temp2->next)
            temp2 = temp2->next;
        temp2->next=head;
        temp->next = NULL;
        head = start;
        }
       
        return head;
        
    }
};