class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        sum-=x;
        if(sum<0)return -1;
        if(sum==0)return n;
        int i=0;
        int j=-1;
        //cout<<j;
        long long temp=0;
        int len =0;
        //if(j<n) cout<<"YES\n";
        while(j<n)
        {
            //cout<<i<<" "<<j<<" "<<temp<<"\n";
            
            if(temp<sum)
            {
                j++;
                if(j<n)
                    temp+=nums[j];
            }
            else
            {
                if(temp==sum)
                {
                    len = max(len , j-i+1);
                    j++;
                    if(j<n)
                        temp+=nums[j];
                }
                temp-=nums[i];
                i++;
            }
        }
        if(len==0)
            return -1;
        return (n-len);
    }
};