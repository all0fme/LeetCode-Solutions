class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        for(int i=0;i<n;i++)
        {
            gas[i] = gas[i]-cost[i];
        }
        int ans =0;
        int mx=INT_MIN;
        for(int i=1;i<n;i++)
            gas[i]+=gas[i-1];
        if(gas[n-1]<0)
            return -1;
        int x ;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                x = gas[n-1];
            else
                x = gas[n-1]- gas[i-1];
            if(x>mx)
            {
                ans =i;
                mx = x;
            }
        }
        return ans;
        
    }
};