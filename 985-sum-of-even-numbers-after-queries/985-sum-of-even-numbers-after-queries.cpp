class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        
        int sum=0;
        
        for(int x:nums)
        {
            if(x%2==0)
                sum+=x;
        }
        vector<int> ans;
        for(auto &x: queries)
        {
            int prev_num = nums[x[1]];
            int new_num = prev_num + x[0];
            nums[x[1]] += x[0];
            
            if(new_num%2==0)
            {
                if(prev_num%2==0)
                {
                    sum+=x[0];
                }
                else{
                    sum+=new_num;
                }
            }
            else{
                
                if(prev_num%2==0)
                {
                    sum-=prev_num;
                }
                
            }
            ans.push_back(sum);
            
        }
        return ans;
        
    }
};