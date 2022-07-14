class Solution {
public:
    
    void solve(vector<vector<int>> & ans,vector<int>& nums,vector<int>& temp,int i)
    {
        if(i>=nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        //take
        temp.push_back(nums[i]);
        solve(ans,nums,temp,i+1);
        temp.pop_back();
        //don't take
        solve(ans,nums,temp,i+1);
        
        
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        int n = nums.size();
        int x = (1<<n);
        for(int j=0;j<(x);j++)
        {
            temp.clear();
            int mask = j;
            
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i))
                    temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};