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
    TreeNode* solve(vector<int>& preorder,int i, int j)
    {
        if(i>j)
            return NULL;
        
        int val = preorder[preInd++];
        TreeNode * node = new TreeNode(val);
        node->left = solve(preorder,i,mp[val]-1);
        node->right = solve(preorder,mp[val]+1,j);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(preorder,0,inorder.size()-1);
        
    }
};