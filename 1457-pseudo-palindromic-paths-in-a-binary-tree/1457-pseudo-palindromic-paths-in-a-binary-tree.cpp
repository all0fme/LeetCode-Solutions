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
    int ans=0;
    void solve(TreeNode* root, unordered_map<int,int> &mp, int ev, int od){
        
        if(!root->right && !root->left)
        {
            if(mp.find(root->val)==mp.end())
            {
                od++;
            }
            else{
                if(mp[root->val]%2)
                {
                    ev++;
                    od--;
                }
                else{
                    od++;
                    ev--;
                }
            }
            if(od<=1)
                ans++;
            return;
        }
        
       mp[root->val]++;
        if(mp[root->val]==1)
        {
            od++;
            
        }
        else{
            if(mp[root->val]%2)
            {
                ev--;
                od++;
            }
            else{
                od--;
                ev++;
            }
        }
        if(root->left)
        {
            solve(root->left,mp,ev,od);
        }
        if(root->right)
          solve(root->right,mp,ev,od);
        mp[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)
            return 0;
        unordered_map<int,int> mp;
        solve(root,mp, 0,0);
        return ans;
    }
};