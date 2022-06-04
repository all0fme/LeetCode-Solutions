class Solution {
public:
    bool isValid( vector<vector<int>> &board,int x,int y)
    {
        int n = board.size();
        for(int j=0;j<=x;j++)
        {
            if(board[j][y]==1)
                return false;
        }
        int i=x,j=y;
        while(i>=0 && j>=0)
        {
            if(board[i][j]==1)
                return false;
            i--,j--;
        }
        i=x,j=y;
        while(i>=0 && j<n)
        {
            if(board[i][j]==1)
                return false;
            i--,j++;
        }
        return true;
    }
    void solve(vector<vector<int>> &board,int row,vector< vector<vector<int>>>&ans){
        
        if(row>=board.size())
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++)
        {
            if(isValid(board,row,i)){
                board[row][i]=1;
                solve(board,row+1,ans);
                board[row][i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector< vector<vector<int>>> ans;
         vector<vector<string>> ANS;
        solve(board,0,ans);
        
        int num = ans.size();
        for(int k=0;k<num;k++)
        {
            vector<string> sol;
             for(int i=0;i<n;i++)
        {
            string temp;
            for(int j=0;j<n;j++)
            {
                if(ans[k][i][j]==0)
                {
                    temp.push_back('.');
                }
                else temp.push_back('Q');
            }
            sol.push_back(temp);
        }
            ANS.push_back(sol);
        }
       
        return ANS;
        
        
    }
};