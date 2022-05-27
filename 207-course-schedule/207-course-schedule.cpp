class Solution {
public:
    
   bool dfs_checkCycle(int node, vector<int>&vis,vector<vector<int>> &graph )
   {
       vis[node]=1;
       for(int child: graph[node])
       {
           if(vis[child]==0)
           {
               if(!dfs_checkCycle(child,vis,graph))return false;
           }
           else if(vis[child]==1)
               return false;
       }
       vis[node]=2;
       
       return true;
       
       
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //vector<int>indeg(numCourses,0);
        vector<int>vis(numCourses,0);
        vector<vector<int>> graph(numCourses);
        
        for(auto &x: prerequisites)
        {
            //indeg[x[1]]++;
            graph[x[0]].push_back(x[1]);
        }
//         int cnt=0;
//         queue<int> q;
//         for(int i=0;i<numCourses;i++)
//         {
//             if(indeg[i]==0)
//             {
//                 q.push(i);
                
//             }
                
//         }
//         while(!q.empty())
//         {
//             int x = q.front();
//             q.pop();
//             cnt++;
//             for(int child: graph[x])
//             {
//                 indeg[child]--;
//                 if(indeg[child]==0)
//                     q.push(child);
//             }
            
            
            
//         }
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(!dfs_checkCycle(i,vis,graph))return false;
            }
        }
        return true;
    }
};