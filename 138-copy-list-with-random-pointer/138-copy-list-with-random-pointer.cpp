/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tempHead = head;
        
        while(tempHead)
        {
            Node * temp = new Node(tempHead->val);
            temp->next = tempHead->next;
            tempHead->next =temp;
            tempHead = tempHead->next->next;
        }
        tempHead = head;
        while(tempHead)
        {
            if( tempHead->random)
            {
                 tempHead->next->random = tempHead->random->next;
            }
            tempHead = tempHead->next->next;
        }
        tempHead = head;
        Node*  tail = new Node(-1);
        Node* dummy = tail;
        while(tempHead)
        {
            dummy->next = tempHead->next;
            dummy = dummy->next;
             tempHead->next = tempHead->next->next;
            tempHead = tempHead->next;
        }
        return tail->next;
    }
};