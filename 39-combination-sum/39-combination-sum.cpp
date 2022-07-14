class Solution {
public:
    
    void solve(vector<vector<int>> &ans, vector<int>& candidates, int target,vector<int>& temp, int i,int sum)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
             ans.push_back(temp);
            return;
        }
            
            
        if(i==candidates.size() )
            return;
        
        //take
        for(int x = i;x<candidates.size();x++)
        {
            temp.push_back(candidates[x]);
        
        solve(ans,candidates,target,temp,x,sum+candidates[x]);
       
        temp.pop_back();
        }
        
           
      
    }
        
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        
        solve(ans,candidates,target,temp,0,0);
        vector<vector<int>> anss(ans.begin(),ans.end());
        return anss;
    }
};