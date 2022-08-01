class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++){
               // cout<<i<<" "<<j<<"\n";
                
                if(board[i][j]!='.'){
                    
                    char c = board[i][j];
                    board[i][j] = '*';
                    for(int k = 0;k<9;k++)
                    {
                        if(board[i][k]==c || board[k][j]==c){
                            return false;
                        }
                    }
                    int r = i/3 *3;
                    int cc = j/3*3;
                    
                    for(int f = r;f<r+3;f++){
                        for(int ff = cc;ff<cc+3;ff++)
                        {
                             if(board[f][ff]==c ){
                            return false;
                        }
                        }
                    }
                    board[i][j] =c;
                }
            }
        }
        return true;
        
    }
};