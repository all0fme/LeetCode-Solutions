class Solution {
public:
    double myPow(double x, int nn) {
        
        int neg =0;
        long long n = nn;
        
        if(n<0)
        {
            neg=1;
            n*=-1;
        }
        
        double ans = 1.0;
        
        while(n>0)
        {
            if(n&1)
                ans = ans*x;
            x= x*x;
            n>>=1;
        }
        if(neg)
            return 1/(ans);
        return ans;
        
    }
};