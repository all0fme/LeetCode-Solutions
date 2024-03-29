class Solution {
public:
   int numDecodings(string s) {
        int n= s.size();
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        if(s[0]=='0')return 0;
        if(n==1)return 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0' && (s[i-1]=='0' ||s[i-1]>='3'))return 0;
            if(s[i]=='0' )
                dp[i+1]=dp[i-1];
            else if( s[i-1]=='1'||(s[i-1]=='2' && s[i]<='6'))
                    dp[i+1]=dp[i]+dp[i-1];
                else
                    dp[i+1]=dp[i];
            
        }
        return dp[n];
    }
};