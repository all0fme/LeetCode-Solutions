class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> temp;
    bitset<10> vis;
    
    void solve(int n,vector<int>& nums)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                temp.push_back(nums[i-1]);
                solve(n,nums);
                temp.pop_back();
                vis[i]=0;
                
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums.size(),nums);
        return ans;
    }
};