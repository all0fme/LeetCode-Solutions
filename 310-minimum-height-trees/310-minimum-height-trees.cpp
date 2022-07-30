class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        vector<int> ans;
        if(n==1){
            return {0};
        }
        for(auto &x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
            indeg[x[1]]++;
            }
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            
            int sz = q.size();
            ans.clear();
            for(int i=0;i<sz;i++){
                         int x = q.front();
                q.pop();
                ans.push_back(x);
                indeg[x]--;
                for(int child: adj[x]){
                    indeg[child]--;
                    if(indeg[child]==1){
                        q.push(child);
                    }
                }
            }
        }
        return ans;
        
            
    }
};