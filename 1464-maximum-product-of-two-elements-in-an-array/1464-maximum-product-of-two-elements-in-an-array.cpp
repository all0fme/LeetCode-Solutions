class Solution {
public:
    int maxProduct(vector<int>& nums) {
      priority_queue<int> pq;
        for(int x: nums)
           pq.push(x);
        int ans = pq.top()-1;
        pq.pop();
        ans*=pq.top()-1;
        return ans;
         
    }
};