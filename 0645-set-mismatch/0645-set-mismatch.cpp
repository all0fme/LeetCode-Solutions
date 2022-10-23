class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        int sum = n*(n+1)/2;
        long long sqrsum = n*(n+1)*(2*n+1)/6;
        int the_sum = 0;
        int the_sqrsum=0;
        for(long long x :nums)
        {
          
            the_sum+=x;
            the_sqrsum+=x*x;
        }
        int M_S= sum-the_sum;
        int m2_s2 = sqrsum-the_sqrsum;
        int MplusS = m2_s2/M_S;
        return {(MplusS-M_S)/2,(M_S+MplusS)/2};
        
    }
};