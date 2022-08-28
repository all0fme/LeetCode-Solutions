class Solution {
public:
    int n;
    int m;
    void solve(vector<vector<int>>& mat,int x,int y)
    {
        int i =x;
        int j = y;
        vector<int> temp;
        while(i<m && j<n)
        {
            temp.push_back(mat[i++][j++]);
            
        }
        sort(temp.begin(),temp.end());
        i = x;
        j =y;
        int k=0;
        while(i<m && j<n)
        {
            mat[i++][j++] = temp[k++];
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        m = mat.size();
        n = mat[0].size();
        
        for(int i=0;i<n;i++)
            solve(mat,0,i);
        for(int i=1;i<m;i++)
            solve(mat,i,0);
        return mat;
    }
};