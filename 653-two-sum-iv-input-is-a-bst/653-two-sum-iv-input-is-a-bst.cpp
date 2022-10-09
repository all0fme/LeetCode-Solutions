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
    vector<int> inOrder;
    
    void traverse(TreeNode* root)
    {
        if(!root)
            return;
        
       
        traverse(root->left);
         inOrder.push_back(root->val);
        traverse(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        
        traverse(root);
        int i=0;
        int j = inOrder.size()-1;
        
        while(i<j)
        {
            if(inOrder[i]+ inOrder[j]==k)
                return true;
            else if(inOrder[i]+ inOrder[j]<k)
                i++;
            else
                j--;
            
        }
        return false;
    }
};