class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        
        for(int x: arr)
        {
            mp[x]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto x: mp)
        {
            pq.push({x.second,x.first});
        }
        int num=0;
         int ans=0;
        while(num<(n/2))
        {
            num+=pq.top().first;
            ans++;
            pq.pop();
            
        }
        return ans;
        
    }
};