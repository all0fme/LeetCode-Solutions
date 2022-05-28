class Solution {
public:
    pair<int,int> dfs(int node,vector<vector<int>>& graph, vector<int>& quiet,vector<int>&vis)
    {
        vis[node]=1;
        
        pair<int,int> ans = {node,quiet[node]};
        
        
        for(int child: graph[node])
        {
            if(!vis[child])
            {
                pair<int,int> temp=dfs(child,graph,quiet,vis);
                if(temp.second<ans.second)
                {
                    ans = temp;
                }
            }
        }
        return ans;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        
        vector<vector<int>> graph(quiet.size());
        
        for(auto &x: richer)
        {
            graph[x[1]].push_back(x[0]);
        }
        vector<int> ans;
        for(int i=0;i<quiet.size();i++)
        {
            vector<int> vis(quiet.size(),0);
            ans.push_back(dfs(i,graph,quiet,vis).first);
        }
        return ans;
        
    }
};