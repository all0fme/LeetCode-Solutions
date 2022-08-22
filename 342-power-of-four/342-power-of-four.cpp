class Solution {
public:
    bool isPowerOfFour(long long n) {
        
       
        bool b1 =((n&(n-1))==0);
        if(!b1)
            return false;
        for(int i=0;i<31;i++)
        {
            if(n&(1<<i))
            {
                if(i%2==0)
                    return true;
                else
                    return false;
            }
        }
        return false;
        
    }
};