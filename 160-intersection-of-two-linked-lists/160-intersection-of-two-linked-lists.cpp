/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA =0;
        int sizeB=0;
        ListNode* temp=headA;
        while(temp)
        {
            sizeA++;
            temp=temp->next;
        }
        temp = headB;
        while(temp)
        {
            sizeB++;
            temp = temp->next;
        }
        if(sizeA<sizeB)
        {
            temp = headB;
            while(sizeB!=sizeA)
            {
                sizeB--;
                temp=temp->next;
            }
            headB=temp;
        }
        else if(sizeB<sizeA)
        {
             temp = headA;
            while(sizeB!=sizeA)
            {
                sizeA--;
                temp=temp->next;
            }
            headA = temp;
        }
        while(headA && headB && headA != headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        
        return headA;
        // if(headA == headB)
        //     return headA;
        // else
        //     return NULL:
    }
};