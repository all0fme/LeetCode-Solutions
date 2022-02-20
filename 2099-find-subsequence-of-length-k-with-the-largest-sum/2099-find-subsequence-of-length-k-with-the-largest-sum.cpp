class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq,pq2;
        int ind=0;
        for(int x: nums)
            pq.push({x,ind++});
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            pq2.push({-pq.top().second,pq.top().first});
            pq.pop();
        }
        while(!pq2.empty())
        {
            ans.push_back(pq2.top().second);
            pq2.pop();
        }
        return ans;
        
    }
};