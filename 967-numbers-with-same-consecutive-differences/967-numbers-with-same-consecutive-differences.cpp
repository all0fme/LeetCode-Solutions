class Solution {
public:
    vector<int> ans;
    int n,k;
   
    void solve(int len,int dig,int num)
    {
        if(len==n)
        {
            ans.push_back(num);
            return;
        }
        
        int x = dig+k;
        int x2 = dig-k;
        
        if(x>=0 && x<=9)
            solve(len+1,x,num*10 + x);
        if(x!=x2 && x2>=0 && x2<=9)
            solve(len+1,x2,num*10 + x2);
        
        
        
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        this->n = n;
        this->k =k;
        for(int i=1;i<=9;i++)
        {
            solve(1,i,i);
        }
        return ans;
    }
};