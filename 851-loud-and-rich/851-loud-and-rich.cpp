class Solution {
public:
    int dfs(int node,vector<vector<int>>& graph, vector<int>& quiet,vector<int>&ans)
    {
        if(ans[node]!=-1)
            return ans[node];
        
        ans[node] = node;
        
        
        
        
        for(int child: graph[node])
        {
           
                int temp=dfs(child,graph,quiet,ans);
                if(quiet[temp]<quiet[ans[node]])
                    ans[node]=temp;
            
        }
        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        
        vector<vector<int>> graph(quiet.size());
        
        for(auto &x: richer)
        {
            graph[x[1]].push_back(x[0]);
        }
       
        vector<int> ans(quiet.size(),-1);
        for(int i=0;i<quiet.size();i++)
        {
            
            dfs(i,graph,quiet,ans);
        }
        return ans;
        
    }
};