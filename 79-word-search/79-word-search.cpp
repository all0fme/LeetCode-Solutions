class Solution {
public:
    vector<vector<int>> vis;
    int m,n;
    bool solve(vector<vector<char>>& board,string word,int ind,int i,int j)
    {
        if(ind==word.size()){
            return true;
        }
        if(i>=m || i<0 || j>=n || j<0)
            return false;
        if(vis[i][j]==0 && board[i][j]==word[ind]){
            vis[i][j]=1;
            if(solve(board,word,ind+1,i+1,j))
                return true;
            if(solve(board,word,ind+1,i-1,j))
                return true;
            if(solve(board,word,ind+1,i,j+1))
                return true;
            if(solve(board,word,ind+1,i,j-1))
                return true;
            vis[i][j]=0;
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
       m = board.size();
         n = board[0].size();
        
        vis.resize(m);
        for(int i=0;i<m;i++){
            vis[i].resize(n,0);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                 
                if(solve(board,word,0,i,j))
                    return true;
                
            }
        }
        return false;
    }
};