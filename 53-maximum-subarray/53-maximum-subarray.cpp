class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int msf =INT_MIN;
        int meh = 0;
        
        int sum =0;
        for(int num:nums){
            meh+=num;
            meh = max(meh,num);
            msf = max(meh,msf);
            
        }
        return msf;
        
    }
};