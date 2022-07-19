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
     unordered_map<int,int> mp;
    int preInd =0;
     TreeNode* solve(vector<int>& postorder,int i, int j)
    {
        if(i>j)
            return NULL;
        
        int val = postorder[preInd--];
        TreeNode * node = new TreeNode(val);
       
        node->right = solve(postorder,mp[val]+1,j);
          node->left = solve(postorder,i,mp[val]-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        preInd = postorder.size()-1;
           for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(postorder,0,inorder.size()-1);
    }
};