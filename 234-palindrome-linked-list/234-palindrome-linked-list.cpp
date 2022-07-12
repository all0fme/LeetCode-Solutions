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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast)
            slow = slow->next;
        fast = slow;
        ListNode* prev = NULL;
        while(fast)
        {
            ListNode* temp = fast->next;
            fast->next = prev;
            prev = fast;
            fast = temp;
        }
        slow = prev;
        fast = head;
        while(slow)
        {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
        
        
    }
};