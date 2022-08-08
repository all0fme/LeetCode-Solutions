class Solution {
public:
    vector<string> ans;
    string temp;
    
    void solve(int n, int cnt,int l,int r)
    {
        
        if(l==n && r==n)
        {
            ans.push_back(temp);
            return;
        }
        if(cnt==0)
        {
            temp.push_back('(');
            solve(n,cnt+1,l+1,r);
            temp.pop_back();
        }
        else
        {
            temp.push_back(')');
            solve(n,cnt-1,l,r+1);
            temp.pop_back();
            
            if(l<n)
            {
                
            temp.push_back('(');
            solve(n,cnt+1,l+1,r);
            temp.pop_back();
            }
        }
       
        
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,0);
        return ans;
    }
};