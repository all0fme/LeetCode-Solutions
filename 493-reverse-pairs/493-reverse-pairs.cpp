class Solution {
public:
    int merge(vector<int>&nums,int l,int mid,int r){
        
        vector<int> temp(r-l+1);
        
        int ptr1 = l;
        int ptr2 = mid+1;
        
        int k =0;
        int ans=0;
        int j = mid + 1;
  for (int i = l; i <= mid; i++) {
    while (j <= r && nums[i] > 2* (long long)nums[j]) {
      j++;
    }
    ans += (j - (mid + 1));
  }
        while(ptr1<=mid && ptr2<=r)
        {
            
            
            if(nums[ptr1]<=nums[ptr2])
            {
                temp[k++] = nums[ptr1++];
            }
            else
            {
                temp[k++]= nums[ptr2++];
            }
        }
        
        while(ptr1<=mid)
            temp[k++] = nums[ptr1++];
        while(ptr2<=r)
            temp[k++]= nums[ptr2++];
        k=0;
        for(int i=l;i<=r;i++)
            nums[i] = temp[k++];
        return ans;
        
        
      
    }
    int merge_sort(vector<int>& nums,int l,int r)
    {
        if(l>=r)
            return 0;
        int ans =0;
        int mid = l + (r-l)/2;
        ans+=merge_sort(nums,l,mid);
        ans+=merge_sort(nums,mid+1,r);
        ans+=merge(nums,l,mid,r);
        return ans;
        
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};