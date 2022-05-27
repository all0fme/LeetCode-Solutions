class Solution {
public:
    
    void bfs_kahn(vector<int>&Indeg, vector<vector<int>> &graph,vector<int>&ans)
    {
        queue<int> q;
        
        for(int i=0;i<graph.size();i++)
        {
            if(Indeg[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int child: graph[node])
            {
                Indeg[child]--;
                if(Indeg[child]==0)
                    q.push(child);
            }
        }
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>Indeg(numCourses,0);
        vector<int> ans;
        
        vector<vector<int>> graph(numCourses);
        
        for(auto &x: prerequisites)
        {
            Indeg[x[0]]++;
            graph[x[1]].push_back(x[0]);
        }
        
        bfs_kahn(Indeg,graph,ans);
        if(ans.size()==numCourses)
            return ans;
        return {};
       
        
    }
};