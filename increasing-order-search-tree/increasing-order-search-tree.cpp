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
    void inorder(TreeNode* root, TreeNode* &curr)
    {
        if(!root)
            return;
        inorder(root->left,curr);
        root->left=NULL;
        curr->right = root;
        curr = root;
        inorder(root->right,curr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *curr= new TreeNode(0);
        TreeNode* ans =curr;
       
        inorder(root,curr);
        
        return ans->right;
        
    }
};