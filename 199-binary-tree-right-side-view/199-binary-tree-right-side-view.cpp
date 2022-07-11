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
    
    int height(TreeNode* node)
    {
        
        if(!node)
            return 0;
        else{
            return 1 + max(height(node->left),height(node->right));
        }
    }
    
    void postorder(TreeNode* node,int h,vector<int>&vec)
    {
         
        if(!node)
            return;
        postorder(node->left,h+1,vec);
        postorder(node->right,h+1,vec);
        vec[h] = node->val;
    }
    vector<int> rightSideView(TreeNode* root) {
        
        int mxht = height(root);
        vector<int> vec(mxht,-1);
        postorder(root,0,vec);
        return vec;
        
    }
};