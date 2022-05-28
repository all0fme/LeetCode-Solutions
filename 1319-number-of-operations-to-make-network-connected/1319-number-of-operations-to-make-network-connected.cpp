class Solution {
public:
    int find_set(int a, vector<int>&parent){
        
        if(parent[a]==a)
            return a;
        return parent[a] = find_set(parent[a],parent);
    }
    void union_set(int a, int b, vector<int>&parent)
    {
        parent[find_set(parent[b],parent)] = find_set(parent[a],parent); 
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> parent(n,0);
        
        for(int i=0;i<n;i++)
            parent[i] =i;
        int cable=0;
        int comp=0;
        for(auto &x: connections){
            
            if(find_set(x[0],parent)==find_set(x[1],parent))
                cable++;
            else
                union_set(x[0],x[1],parent);
        }
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                comp++;
                
        }
        if(cable>=(comp-1))
            return comp-1;
        else
            return -1;
        
        
    }
};