class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pt;
        
        for(int i=0;i<numRows;i++)
        {
            vector<int> tmp;
            for(int j=0;j<i;j++)
            {
                if(j==0)
                    tmp.push_back(1);
                else
                {
                    tmp.push_back(pt[i-1][j] + pt[i-1][j-1]);
                }
            }
            
           // if(i!=0)
                tmp.push_back(1);
         pt.push_back(tmp);
        }
       return pt;
        
    }
};