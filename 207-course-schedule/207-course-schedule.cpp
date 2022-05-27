class Solution {
public:
    
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>indeg(numCourses,0);
        vector<vector<int>> graph(numCourses);
        
        for(auto &x: prerequisites)
        {
            indeg[x[1]]++;
            graph[x[0]].push_back(x[1]);
        }
        int cnt=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                
            }
                
        }
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            cnt++;
            for(int child: graph[x])
            {
                indeg[child]--;
                if(indeg[child]==0)
                    q.push(child);
            }
            
            
            
        }
        return (cnt == numCourses);
    }
};