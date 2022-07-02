class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long maxh =0;
        long long maxw = 0;
        for(int i=0;i< horizontalCuts.size()-1;i++)
        {
            maxh = max((int)maxh,horizontalCuts[i+1]-horizontalCuts[i]);
            
        }
        for(int i=0;i< verticalCuts.size()-1;i++)
        {
            
            maxw = max((int)maxw,verticalCuts[i+1]-verticalCuts[i]);
        }
        return (maxh*maxw)%(1000000007);
        
    }
};