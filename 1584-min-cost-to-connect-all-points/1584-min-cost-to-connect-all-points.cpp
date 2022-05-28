class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                adj[i].push_back({abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1]),j});
                adj[j].push_back({abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1]),i});
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        
        int ans=0;
        
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node])
                continue;
            vis[node]=1;
            
            
            ans+=dis;
            for( auto child: adj[node])
            {
                if(!vis[child.second])
                {
                    pq.push(child);
                }
            }
            
        }
        return ans;
        
    }
};