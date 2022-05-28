class Solution {
public:
    unordered_map<int,vector<int>> row,col;
    int dfs(vector<vector<int>>&stones,int index,vector<bool>&visited,int&n){
        visited[index]=true;
        int result=0;
        for(int x: row[stones[index][0]])
        {
            if(!visited[x])
                result+=(dfs(stones,x,visited,n) + 1);
        }
        for(int x: col[stones[index][1]])
        {
            if(!visited[x])
                result+=(dfs(stones,x,visited,n) + 1);
        }
        // for(int i=0;i<n;i++)
        //     if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
        //         result +=(dfs(stones,i,visited,n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool>visited(n,0);
        int result=0;
        
        for(int i=0;i<n;i++)
        {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
            
        }
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            result+=dfs(stones,i,visited,n);
        }
        return result;
    }
};