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
        if(!head)
            return NULL;
        Node *tempHead = head;
        Node *dummy= new Node(0);
        Node* newHead = dummy;
        unordered_map<Node*,Node*> mp;
        while(tempHead)
        {
             if(mp.find(tempHead)!=mp.end())
                {
                    newHead->next = mp[tempHead];
                }
            else{
                newHead->next = new Node(tempHead->val);
            mp[tempHead] = newHead->next;
            }
            
            if(tempHead->random)
            {
                if(mp.find(tempHead->random)!=mp.end())
                {
                    newHead->next->random = mp[tempHead->random];
                }
                else{
                    newHead->next->random = new Node(tempHead->random->val);
                    mp[tempHead->random] = newHead->next->random;
                }
            }
            tempHead = tempHead->next;
            newHead = newHead->next;
                
        }
        return dummy->next;
    }
};