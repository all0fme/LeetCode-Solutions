class Solution {
public:
    bool isPowerOfFour(long long n) {
        
       
        bool b1 =((n&(n-1))==0);
        bool b2 = (n-1)%3==0;
        
        return (b1&&b2);
        
    }
};