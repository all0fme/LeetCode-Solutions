//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int> indeg;
	vector<int> topo;
	vector<int> vis;
	
	void findTopoSortbfs(vector<int> adj[])
	{
	    queue<int> q;
	    
	    for(int i=0;i<indeg.size();i++)
	    {
	        if(indeg[i]==0)
	        q.push(i);
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(int child: adj[node])
	        {
	            indeg[child]--;
	            if(indeg[child]==0)
	            q.push(child);
	        }
	    }
	    
	}
	
	void findTopoSortdfs(vector<int> adj[],int node)
	{
	    vis[node] =1;
	    for(int child: adj[node])
	    {
	        if(!vis[child])
	        {
	            findTopoSortdfs(adj,child);
	        }
	    }
	    topo.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vis.resize(V,0);
	   // indeg.resize(V,0);
	   // for(int i=0;i<V;i++)
	   // {
	   //     for(int x: adj[i])
	   //     {
	   //         indeg[x]++;
	   //     }
	   // }
	    for(int i=0;i<V;i++)
	    {
	      if(!vis[i])
	      findTopoSortdfs(adj,i);
	    }
	   reverse(topo.begin(),topo.end());
	    return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends