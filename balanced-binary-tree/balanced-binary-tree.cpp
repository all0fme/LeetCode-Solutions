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
    bool res = true;
    int depth(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        if(abs(l-r)>1 || (l==-1)|| r==-1 )
          return -1 ;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        if(depth(root)==-1)
            return false;
        return true;
        
        
    }
};