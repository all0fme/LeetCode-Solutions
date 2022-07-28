class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        int mxlen=1;
        int st=0,e=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            if(i!=n-1 && s[i]==s[i+1] )
            {
                
                dp[i][i+1]= 1;
                mxlen=2;
                st=i;
                e =i+1;
            }
        }
        
        for(int i=n-3;i>=0;i--)
        {
            for(int j=i+2;j<n;j++){
                if(s[i]==s[j] && dp[i+1][j-1]==1 ){
                    dp[i][j]= 1;
                   if((j-i+1)>mxlen)
                   {
                       mxlen = j-i+1;
                       st = i;
                       e =j;
                   }
                }
                else{
                    dp[i][j] =0;
                }
            }
        }
        
        return s.substr(st,mxlen);
    }
};