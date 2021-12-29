/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            mp[temp.second.second][temp.second.first].insert(node->val);
            if(node->left)
            {
                q.push({node->left,{temp.second.first+1,temp.second.second-1}});
            }
            if(node->right)
            {
                q.push({node->right,{temp.second.first+1,temp.second.second+1}});
            }
        }
        for(auto vertical:mp)
        {
            vector<int> seg;
            for(auto lev: vertical.second)
                seg.insert(seg.end(),lev.second.begin(),lev.second.end());
            ans.push_back(seg);
        }
        return ans;
    }
};