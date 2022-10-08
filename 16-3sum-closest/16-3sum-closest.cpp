class Solution {
public:
    
    int les_min = INT_MAX;
    int grt_min = INT_MAX;
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0;i<n-2;i++)
        {
            int ptr1 = i+1;
            int ptr2 = n-1;
            
            int sum = nums[i]+nums[ptr1]+nums[ptr2];
            while(ptr1<ptr2)
            {
                if( nums[i]+nums[ptr1]+nums[ptr2]>=target)
                {
                    grt_min = min( nums[i]+nums[ptr1]+nums[ptr2]-target,grt_min);
                    
                   ptr2--;
                    
                }
                else{
                    
                    les_min = min(les_min,target- nums[i]-nums[ptr1]-nums[ptr2]);
                    ptr1++;
                    
                   
                }
            }
            
        }
        if(grt_min<les_min)
            return target+ grt_min;
        else
            return target-les_min;
        
    }
};