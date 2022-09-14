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
    //int ans=0;
    int solve(TreeNode* root, unordered_map<int,int> &mp, int ev, int od){
        
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
                return 1;
            return 0;
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
        int ans=0;
        if(root->left)
        {
            ans+=solve(root->left,mp,ev,od);
        }
        if(root->right)
         ans+= solve(root->right,mp,ev,od);
        mp[root->val]--;
        return ans;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)
            return 0;
        unordered_map<int,int> mp;
        return solve(root,mp, 0,0);
        
    }
};