class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1e9+7;
        
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i] = {efficiency[i],speed[i]};
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        
       long max_power = 0;
        
        int i=0;
        int j=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        long sum=0;
        while(i<n)
        {
            if(j<i)
            {
                pq.push(vec[j].second);
                sum=(sum+(vec[j].second));
                j++;
                
                if(pq.size()>(k-1))
                {
                    sum=(sum-pq.top());
                    pq.pop();
                }
                    
            }
            max_power = max(max_power,(sum+vec[i].second)*vec[i].first);
            //cout<<i<<" "<<max_power<<"\n";
            i++;
        }
        return max_power%mod;
        
    }
};