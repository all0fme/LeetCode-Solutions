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
    vector<int> temp;
    void solve(TreeNode* root, vector<  vector<int>> &ans)
    {
        if(!root->left && !root->right)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
         temp.push_back(root->val);
        if(root->left)
        {
           
            solve(root->left,ans);
            
        }
        if(root->right)
        {
             
            solve(root->right,ans);
           
        }
          temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return {};
        
        solve(root,ans);
        vector<string>sol;
        for(auto &tmp: ans)
        {
            if(tmp.size()==1)
            {
                sol.push_back(to_string(tmp[0]));
            }
            else{
                string tempp;
                for(int i=0;i<tmp.size()-1;i++)
                {
                    tempp+=to_string(tmp[i])+"->";
                }
                tempp+=to_string(tmp[tmp.size()-1]);
                sol.push_back(tempp);
            }
            
        }
        return sol;
            
        
    }
};