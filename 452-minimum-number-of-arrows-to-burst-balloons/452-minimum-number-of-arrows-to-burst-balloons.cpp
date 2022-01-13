class Solution {
    
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return b[1]>a[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int currEnd=points[0][1];
        int arrow=1;
        for(int i=1;i<points.size();i++)
        {
            if(!(points[i][0]<=currEnd))
            {
               arrow++; 
                currEnd = points[i][1];
            
            }
            else
                currEnd = min(currEnd,points[i][1]);
            
                
                
        }
        return arrow;
        
    }
};