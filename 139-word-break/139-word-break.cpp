class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1,false);
        unordered_set<string> mp;
        for(string x: wordDict)
            mp.insert(x);
        
        dp[n] = true;
        
        for(int i=n-1;i>=0;i--)
        {
            string ss;
           for(int j=i;j<n;j++)
           {
               ss.push_back(s[j]);
               if(mp.find(ss)!=mp.end())
               {
                   dp[i] = dp[j+1];
                   if(dp[i])
                       break;
               }
           }
        }
        return dp[0];
        
    }
};