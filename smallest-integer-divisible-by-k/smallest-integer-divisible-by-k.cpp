class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r=0;
        int n;
        
        for(int i=0;i<k;i++)
        {
            n= r*10 +1;
            if(n%k==0)
                return i+1;
            r = n%k;
            
            
        }
        return -1;
        
    }
};