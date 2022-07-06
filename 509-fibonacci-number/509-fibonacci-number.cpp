class Solution {
public:
    int fib(int n) {
        int f0=0;
        int f1=1;
        if(n==0)
            return 0;
        for(int i=2;i<=n;i++)
        {
            int temp = f1;
            f1+=f0;
            f0=temp;
            
        }
        return f1;
        
    }
};