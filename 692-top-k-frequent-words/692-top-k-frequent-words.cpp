class Solution {
public:
    struct myComp{
         bool operator ()(const pair<int,string>&a,const pair<int,string>&b){
         
        return a.first>b.first || (a.first==b.first && a.second<b.second);
    
             
    }
    };
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,myComp> pq;
        
        unordered_map<string,int> mp;
        
        for(string word: words)
            mp[word]++;
        for(auto &x: mp)
        {
            pq.push({x.second,x.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<string> ans(k);
        for(int i=0;i<k;i++){
            ans[k-1-i] = pq.top().second;
            pq.pop();
        }
        return ans;
        
    }
};