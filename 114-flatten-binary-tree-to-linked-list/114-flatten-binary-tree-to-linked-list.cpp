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
    TreeNode* solve(TreeNode* root){
        if(!root)
            return root;
        TreeNode* rl = solve(root->left);
        TreeNode* rr = solve(root->right);
        
        if(!rl && !rr)
            return root;
        if(!rl){
            root->right = rr;
            root->left = NULL;
            return root;
        }
        if(!rr){
            root->right = rl;
            root->left = NULL;
            return root;
        }
        
        root->right = rl;
        while(rl->right)
        {
            rl = rl->right;
        }
        rl->right = rr;
        root->left = NULL;
        return root;
        
        
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};