class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        int ans;
        while(k)
        {
            ans=pq.top();
            pq.pop();
            k--;
        }
        return ans;
        
        
    }
};