class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& rooms, vector<int>& vis)
             {
                 vis[node] =true;
                 
                 for(int child: rooms[node])
                 {
                     if(!vis[child])
                         dfs(child,rooms,vis);
                         
                 }
             }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<int> vis(rooms.size(),0);
        
        dfs(0,rooms,vis);
        
        for(int i=0;i<rooms.size();i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
        
    }
};