class Solution {
public:
    
    void solve(set<vector<int>> &ans, vector<int>& candidates, int target,vector<int>& temp, int i,int sum)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
             ans.insert(temp);
            temp;
        }
            
            
        if(i==candidates.size() )
            return;
        
        //take
        temp.push_back(candidates[i]);
        
        solve(ans,candidates,target,temp,i,sum+candidates[i]);
       
        temp.pop_back();
        
        //don't take
        solve(ans,candidates,target,temp,i+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        
        
        solve(ans,candidates,target,temp,0,0);
        vector<vector<int>> anss(ans.begin(),ans.end());
        return anss;
    }
};