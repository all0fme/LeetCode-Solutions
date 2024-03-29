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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        vector<double> ans;
        
        q.push(root);
        while(!q.empty()){
            
            double x = q.size();
            double sum=0;
            
            for(int i=0;i<x;i++)
            {
                auto t = q.front();
                q.pop();
                sum+=t->val;
                
                if(t->left)
                q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            ans.push_back(sum/x);
        }
        return ans;
    }
};