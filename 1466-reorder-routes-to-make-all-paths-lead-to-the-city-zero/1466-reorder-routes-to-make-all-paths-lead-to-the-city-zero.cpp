class Solution {
public:
    
    void dfs(int node, vector<vector<int>> &graph,int &res,vector<int>&vis, set<pair<int,int>> &st)
    {
        vis[node]=1;
        
        for(auto child :graph[node])
        {
            if(vis[child]==0)
            {
                if(st.find({node,child})!= st.end())res++;
                dfs(child,graph,res,vis,st);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        vector<int> vis(n,0);
        set<pair<int,int>> st;
        
        for(auto &x: connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            st.insert({x[0],x[1]});
        }
        int res =0;
        dfs(0,graph,res,vis,st);
        return res;
        
    }
};