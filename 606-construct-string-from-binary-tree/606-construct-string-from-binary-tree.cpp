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
    string s;
    void tree2strr(TreeNode* root) {
        
        if(!root)
            return;
        
        s+=to_string(root->val);
        if(root->right)
        {
            s.push_back('(');
            tree2str(root->left);
             s.push_back(')');
             s.push_back('(');
            tree2str(root->right);
             s.push_back(')');
            
        }
        else{
            if(root->left)
            {
                  s.push_back('(');
            tree2str(root->left);
                s.push_back(')');
            
            }
           
        }
       
        
    }
    string tree2str(TreeNode* root) {
        
      tree2strr(root);
        
        return s;
        
    }
};