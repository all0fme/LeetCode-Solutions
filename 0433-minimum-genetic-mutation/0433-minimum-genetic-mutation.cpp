class Solution {
public:
    vector<vector<int>>adj;
    bool isNext(string &s1,string &s2){
        
        int i=0;
        int mut=0;
        for(int i=0;i<8;i++)
        {
            if(s1[i]!=s2[i])
                mut++;
            
        }
        return mut==1;
    }
    
    void bfs(int node, vector<int>&vis)
    {
        queue<int> q;
        q.push(node);
        vis[node]=0;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(int child: adj[temp])
            {
                if(vis[child]==-1)
                {
                    vis[child] = 1+ vis[temp];
                    q.push(child);
                }
            }
        }
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
         
        int n = bank.size();
        adj.resize(n+2);
        int endno =n+2;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i!=j && isNext(bank[i],bank[j])){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                    }
            }
            
            if(isNext(start,bank[i]))
            {
                adj[0].push_back(i+1);
                adj[i+1].push_back(0);
            }
            if(bank[i]==end)
            {
                endno = i+1;
            }
        }
        vector<int> vis(n+3,-1);
        bfs(0,vis);
        return vis[endno];
       
    }
};