class Solution {
public:
    
    void dfs(int node, vector<int>&path, vector<vector<int>>& ans, vector<vector<int>>& graph){
        
        //vis[node] = true;
        path.push_back(node);
        if(node == graph.size()-1)
            ans.push_back(path);
        
        for(int child: graph[node])
        {
            
                dfs(child,path,ans,graph);
        }
        path.pop_back();
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
          vector<int> path; 
        vector<vector<int>> ans;
        
        dfs(0,path,ans,graph);
        
        return ans;
    }
};