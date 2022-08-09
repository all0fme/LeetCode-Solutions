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
    unordered_map<long,int> mp;
    int ans =0;
    bool chance =false;
    
    void solve(TreeNode* root, long long sum, int targetSum)
    {
        if(!root)
            return;
        sum+=root->val;
    
        if(sum==targetSum )
            ans++;
       
        ans+= mp[sum-targetSum];
        mp[sum]++;
        
        
        if(root->left)
            solve(root->left,sum,targetSum);
        if(root->right)
            solve(root->right,sum,targetSum);
       
        mp[sum]--;
        
        
        
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        solve(root,0,targetSum);
        
        return ans;
    }
};