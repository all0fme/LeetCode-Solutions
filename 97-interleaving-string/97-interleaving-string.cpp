class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length(),len2=s2.length(),len3=s3.length();
        if((len1+len2)!=len3)return false;
        
       bool dp[len2+1];
        
        for(int i=0;i<=len1;i++)
            for(int j=0;j<=len2;j++)
            {
                if(i==0 && j==0) dp[j]=true;
                else if(i==0) dp[j]=dp[j-1] && s3[j-1]==s2[j-1];
                else if(j==0) dp[j]=dp[j] && s3[i-1] ==s1[i-1];
                else dp[j] =(dp[j-1] && s3[i+j-1]==s2[j-1]) || (dp[j] && s3[i+j-1] ==s1[i-1]);
            }
        return dp[len2];
    }
};