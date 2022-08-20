class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int> pq;
        
        int tank = startFuel;
        int n = stations.size();
        int ans =0;
        int prev=0;
        
        for(int i=0;i<n;i++)
        {
            tank-=stations[i][0]-prev;
            
            while(!pq.empty() && tank<0)
            {
                tank+=pq.top();
                pq.pop();
                ans++;
            }
            if(tank<0)
                return -1;
            pq.push(stations[i][1]);
            prev = stations[i][0];
        }
        tank-=target-prev;
        while(!pq.empty() && tank<0)
            {
                tank+=pq.top();
                pq.pop();
                ans++;
            }
            if(tank<0)
                return -1;
        return ans;
        
    }
};