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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>> pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            pq.push({-(lists[i]->val),lists[i]});
        }
        ListNode * head = new ListNode();
        ListNode* curr = head;
        while(!pq.empty())
        {
            curr->next = new ListNode(-pq.top().first);
            curr = curr->next;
           
            auto temp = pq.top();
            pq.pop();
            if(temp.second->next)
            {
                temp.second = temp.second->next;
                temp.first = -temp.second->val;
                pq.push(temp);
            }
        }
        return head->next;
    }
};