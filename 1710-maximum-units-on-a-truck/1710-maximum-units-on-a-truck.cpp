class Solution {
public:
    static bool cmp(vector<int>& a, vector<int> &b)
    {
        
        if(a[1]!=b[1])
        {
            return a[1]>b[1];
        }
        return a[0]>b[0];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int trucksize) {
        
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        
        for(auto &x: boxTypes)
        {
            if(x[0]<=trucksize)
            {
                trucksize-=x[0];
                ans+=x[1]*x[0];
            }
            else{
                ans+=(x[1]*trucksize);
                trucksize =0;
            }
            
            if(!trucksize)
                break;
        }
        return ans;
        
        
    }
};