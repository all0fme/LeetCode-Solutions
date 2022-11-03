class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
         unordered_map<string,long long> mp;
        unordered_map<string,map<string,long long>> mpp;
        int n = creators.size();
        long long mx =LLONG_MIN;
        for(int i =0 ;i<n;i++)
        {
            mp[creators[i]]+=views[i];
            mx = max(mx,mp[creators[i]]);
            mpp[creators[i]][ids[i]]+=views[i];
        }
        
       
        vector<string> cc;
        for(auto &x: mp)
        {
            if(x.second==mx)
            {
                cc.push_back(x.first);
            }
        }
        vector<vector<string>> ans;
        for(string &s: cc)
        {
            long long vv =LLONG_MIN;
            string ss = "zzzzzz";
            for(auto &x: mpp[s])
            {
                if(x.second>vv)
                {
                    vv = x.second;
                    ss = x.first;
                }
                else if(x.second==vv)
                {
                    ss = min(ss,x.first);
                }
            }
            ans.push_back({s,ss});
        }
       // cout<<mpp["l"]["vy"]<<" "<<mpp["l"]["a"]<<"\n"; 
        return ans;
    }
};