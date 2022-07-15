class Solution {
public:
    
    vector<vector<int>> ans;
    
   
    
    void solve(int n,vector<int>& nums,int ind)
    {
        if(ind==n)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
                swap(nums[ind],nums[i]);
                solve(n,nums,ind+1);
                swap(nums[ind],nums[i]);
                
                
                
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums.size(),nums,0);
        return ans;
    }
};