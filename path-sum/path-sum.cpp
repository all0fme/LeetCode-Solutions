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
    bool solve(TreeNode * root,int targetSum,int sum)
    {
        if(!root->left && !root->right)
        {
            if(sum+root->val == targetSum)
                return true;
            else
                return false;
        }
        if(!root->left)
        {
            return solve(root->right,targetSum,sum+root->val);
        }
        if(!root->right)
        {
          return solve(root->left,targetSum,sum+root->val);
        }   
        return solve(root->right,targetSum,sum+root->val)|solve(root->left,targetSum,sum+root->val);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root,targetSum,0);
    }
};