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
            if(x!=i && candidates[x]==candidates[x-1])continue;
            temp.push_back(candidates[x]);
        
        solve(ans,candidates,target,temp,x+1,sum+candidates[x]);
       
        temp.pop_back();
        }
        
           
      
    }
        
     
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin(),candidates.end());
        solve(ans,candidates,target,temp,0,0);
        
        return ans;
    }
};