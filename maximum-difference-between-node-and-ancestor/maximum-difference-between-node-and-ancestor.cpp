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
    
    void postorder(TreeNode* root,int mx,int mn,int&diff)
    {
        if(!root)
            return;
        mx = max(root->val,mx);
        mn = min(root->val,mn);
        diff = max(diff,abs(mx-mn));
        postorder(root->left,mx,mn,diff);
        postorder(root->right,mx,mn,diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        postorder(root,INT_MIN,INT_MAX,diff);
        return diff;
    }
};