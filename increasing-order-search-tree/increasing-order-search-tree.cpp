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
    void inorder(TreeNode* root, vector<TreeNode*>&q)
    {
        if(!root)
            return;
        inorder(root->left,q);
        q.push_back(root);
        inorder(root->right,q);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> q;
        inorder(root,q);
        
        for(int i=0;i<q.size()-1;i++)
        {
            q[i]->left=NULL;
            q[i]->right = q[i+1];
        }
        q[q.size()-1]->left = NULL;
        q[q.size()-1]->right = NULL;
        
        root = q[0];
        return root;
        
    }
};