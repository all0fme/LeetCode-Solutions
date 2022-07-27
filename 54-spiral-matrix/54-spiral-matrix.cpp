class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        int up = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        
        int i=0;
        vector<int> ans;
        int cnt =0;
        while(true)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[up][i]);
                cnt++;
            }
            if(cnt == (m*n))
                break;
            up++;
            for(int i=up;i<=down;i++)
            {
                ans.push_back(matrix[i][right]);
                cnt++;
            }
            if(cnt == (m*n))
                break;
            right--;
            for(int i = right;i>=left;i--)
            {
                ans.push_back(matrix[down][i]);
                cnt++;
            }
            if(cnt == (m*n))
                break;
            down--;
            for(int i=down;i>=up;i--){
                ans.push_back(matrix[i][left]);
                cnt++;
            }
            if(cnt == (m*n))
                break;
            left++;
        }
        return ans;
        
    }
};