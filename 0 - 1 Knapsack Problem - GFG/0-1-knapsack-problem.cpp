//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int solve(int w,int *wt, int *val,int n,int i)
    {
        if(i>=n)
        return 0;
        
        if(dp[w][i]!=-1)
        return dp[w][i];
        //Take
        int take =0;
        if(wt[i]<=w)
        {
            take = val[i] + solve(w-wt[i],wt,val,n,i+1);
        }
        //don't take
        int dtake = 0;
        
        dtake = solve(w, wt,val,n,i+1);
        
        return dp[w][i] = max(take,dtake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    
        dp.resize(W+1);
        for(int i=0;i<=W;i++)
        dp[i].resize(n);
        
        for(int i=0;i<=W;i++)
        {
            for(int j=0;j<n;j++)
            dp[i][j]=-1;
        }

       return solve(W,wt,val,n,0);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends