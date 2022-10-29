class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i] = {growTime[i],plantTime[i]};
        }
        sort(vec.begin(),vec.end(),[&] (const pair<int,int> a, const pair<int,int> b){
                                      return a.first>b.first           ;                                    });
        int prevDay =0;
        int maxBloom = 0;
        
        for(auto &x: vec)
        {
            //cout<<x.first<< " "<<x.second<<"\n";
            prevDay+=x.second;
            maxBloom = max(maxBloom,x.first+prevDay);
           // cout<<prevDay<<" "<<maxBloom<<"\n";
        }
        return maxBloom;
    }
};