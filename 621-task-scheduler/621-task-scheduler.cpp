class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        
        int mx =0;
        for(char c: tasks){
            mp[c]++;
            mx = max(mx,mp[c]);
        }
        int free = (mx-1)*(n+1);
        
        for(auto x: mp)
        {
            if(x.second==mx)free++;
        }
        
        return max((int)tasks.size(),free);
    }
};