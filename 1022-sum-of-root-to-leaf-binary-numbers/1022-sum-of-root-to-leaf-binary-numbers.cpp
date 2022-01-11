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
    int sum=0;
    
    void preorder(TreeNode* root, int curr)
    {
        if(!root)
            return;
        curr= curr*2 + root->val;
        if(!root->left && !root->right)
            sum+= curr;
        preorder(root->left,curr);
        preorder(root->right,curr);
        
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        return sum;
    }
};