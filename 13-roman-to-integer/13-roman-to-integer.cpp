class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        int ans =0;
        int prev =INT_MAX;
        
        for(char c: s)
        {
            if(prev<mp[c])
            {
                ans-=2*prev;
            }
                
            ans = ans + mp[c];
            prev = mp[c];
        }
        return ans;
    }
};