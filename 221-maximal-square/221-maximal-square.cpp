class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n+1,0),cur(n+1,0);
        int mx=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    cur[j] = min({cur[j-1],prev[j-1],prev[j]})+1;
                    mx = max(mx,cur[j]);
                    
                }
                else
                    cur[j] =0;
                
            }
           prev = cur;
        }
        return mx*mx;
        
    }
};