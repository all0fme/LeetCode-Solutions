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
          //don't take
        solve(ans,candidates,target,temp,i+1,sum);
        //take
        temp.push_back(candidates[i]);
        
        solve(ans,candidates,target,temp,i,sum+candidates[i]);
       
        temp.pop_back();
           
      
    }
        
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        
        solve(ans,candidates,target,temp,0,0);
        vector<vector<int>> anss(ans.begin(),ans.end());
        return anss;
    }
};