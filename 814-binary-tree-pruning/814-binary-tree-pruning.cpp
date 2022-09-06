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
    
    bool solve(TreeNode* root){
        if(!root)return false;
        bool lc = solve(root->left);
        bool rc = solve(root->right);
        
        if(!lc)
            root->left = NULL;
        if(!rc)
            root->right = NULL;
        
        if(lc || rc || root->val == 1)
            return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!root)
            return root;
        
        if(solve(root))
            return root;
        else
            return NULL;
        
        
        
    }
};