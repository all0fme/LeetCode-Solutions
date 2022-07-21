/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    unordered_map<Node*,bool> vis;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        
        queue<Node*> q;
        
        q.push(node);
        
       
        
        while(!q.empty())
        {
            Node * temp = q.front();
            q.pop();
            
            if(mp.find(temp)==mp.end())
            {
                 mp[temp] = new Node(temp->val);
            }
           
            
            for(auto child: temp->neighbors)
            {
                if(mp.find(child)==mp.end())
                {
                    Node* tempChild = new Node(child->val);
                    mp[child] = tempChild;
                     q.push(child);
                    
                }
                mp[temp]->neighbors.push_back(mp[child]);
               
               
            }
        }
        return mp[node];
        
        
        
        
    }
};