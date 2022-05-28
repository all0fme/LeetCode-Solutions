class Solution {
public:
    
    void dfs(int node, vector<vector<int>> &graph,int &res,int par, set<pair<int,int>> &st)
    {
        
        
        for(auto child :graph[node])
        {
            if(child!=par)
            {
                if(st.find({node,child})!= st.end())res++;
                dfs(child,graph,res,node,st);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        //vector<int> vis(n,0);
        set<pair<int,int>> st;
        
        for(auto &x: connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            st.insert({x[0],x[1]});
        }
        int res =0;
        dfs(0,graph,res,-1,st);
        return res;
        
    }
};