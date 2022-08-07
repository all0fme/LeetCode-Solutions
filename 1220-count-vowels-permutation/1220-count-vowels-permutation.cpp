class Solution {
public:
    int n;
    vector<char> vov = {'a','e','i','o','u'};
    long long mod;
    vector<vector<int>> dp;
    int solve(int ind,char prev)
    {
        
        int ans=0;
        if(ind>=n)
            return 1;
        if(prev=='z')
        {
            
            for(int i=0;i<5;i++)
            {
               ans+= solve(ind+1,vov[i]);
                ans%=mod;
            }
            return dp[ind][prev-'a']=ans;
        }
        if(dp[ind][prev-'a']!=-1)
            return dp[ind][prev-'a'];
        else if(prev=='a'){
            return dp[ind][prev-'a']=solve(ind+1,'e')%mod;
        }
        else if(prev=='e'){
            return dp[ind][prev-'a']=(solve(ind+1,'a')%mod + solve(ind+1,'i')%mod)%mod;
        }
        else if(prev=='i'){
            for(int i=0;i<5;i++)
            {
                if(i==2)
                    continue;
                ans+=solve(ind+1,vov[i]);
                ans%=mod;
            }
            return dp[ind][prev-'a']=ans;
        }
        else if(prev=='o'){
            return dp[ind][prev-'a']=(solve(ind+1,'i')%mod + solve(ind+1,'u')%mod)%mod;
        }
        else{
             return dp[ind][prev-'a']=solve(ind+1,'a')%mod;
        }
        
    }
    int countVowelPermutation(int n) {
        this->n = n;
        this->mod = 1e9+7;
        dp.resize(n);
        for(int i=0;i<n;i++)
        {
            dp[i].resize(26,-1);
        }
        return solve(0,'z');
    }
};