class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = neededTime.size();
        int ans=0;
        int i=1;
        while(i<n)
        {
            
            if(colors[i]==colors[i-1])
            {
                int mn =neededTime[i-1];
                ans+=neededTime[i-1];
                
                while(i<n && colors[i]==colors[i-1])
                {
                    mn = max(mn,neededTime[i]);
                    ans+=neededTime[i];
                    i++;
                }
                ans-=mn;
            }
            else
                i++;
        }
        return ans;
        
    }
};