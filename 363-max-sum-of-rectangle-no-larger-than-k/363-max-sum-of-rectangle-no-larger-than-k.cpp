class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        int mx = -1e9;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                set<int> st;
                st.insert(0);
                int cur=0;
               
                    for(int f = 0;f<m;f++)
                    {
                        cur += matrix[f][j]-(i==0?0:matrix[f][i-1]);
                        auto it = st.lower_bound(cur-k);
                        if(it!=st.end())
                        {
                            mx = max(mx,cur - (*it));
                        }
                        st.insert(cur);
                        
                    }
                
            }
        }
        return mx;
        
    }
};