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
    int mx=-1e9;
    int maxPathSum2(TreeNode* root) {
        if(!root)
            return 0;
        int ls = max(0,maxPathSum2(root->left));
        int rs =max(0,maxPathSum2(root->right));
        
        mx = max(mx,root->val+ls+rs);
        
        return root->val + max(ls,rs);
        
        
        
    }
     int maxPathSum(TreeNode* root) {
         
         if(root)
            mx = root->val; 
         
          maxPathSum2(root);
         return mx;
     }
};