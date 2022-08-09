class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<long long> dp(n,1);
        long long mod = 1e9+7;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        long long ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((arr[i]%arr[j])==0 && mp.find(arr[i]/arr[j])!=mp.end())
                {
                    //cout<<"here\n";
                    dp[i] = (dp[i] + dp[j]*dp[mp[arr[i]/arr[j]]])%mod;;
                    
                }
            }
            ans = (ans+dp[i])%mod;
        }
        return ans;
    }
};