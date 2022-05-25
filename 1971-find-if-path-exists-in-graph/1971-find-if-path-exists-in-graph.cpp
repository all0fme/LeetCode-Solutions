class Solution {
public:
    
    int find_set(int a,vector<int>& parent)
    {
        if(parent[a] == a)
            return a;
        return parent[a] = find_set(parent[a],parent);
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> parent(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(auto x: edges)
        {
            int a = find_set(x[0],parent);
            int b = find_set(x[1],parent);
            
            if(a!=b)
                parent[b] = a;
            
        }
        
        return find_set(source,parent) == find_set(destination,parent);
        
    }
};