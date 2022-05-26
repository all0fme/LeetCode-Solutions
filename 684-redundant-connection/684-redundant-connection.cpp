class Solution {
public:
    int find_set(int a,vector<int>&parent)
    {
        if(parent[a]==a)
            return a;
        return parent[a]=find_set(parent[a],parent);
    }
    void union_set(int a,int b,vector<int>& parent)
    {
        parent[find_set(b,parent)] = find_set(a,parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        for(int i=0;i<=edges.size();i++)
        {
            parent[i] =i;
        }
        
        for(auto &x : edges)
        {
            if(find_set(x[0],parent)==find_set(x[1],parent))
                return x;
            union_set(x[0],x[1],parent);
        }
        return {-1,-1};
        
        
    }
};