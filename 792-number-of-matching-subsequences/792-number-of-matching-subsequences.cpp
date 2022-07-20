class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
        }
        int ans =0;
        for(string str: words)
        {
            int x=-1;
            int flag=1;
            
            for(char ch: str)
            {
                int z = upper_bound(mp[ch].begin(),mp[ch].end(),x) - mp[ch].begin();
                if(z!=mp[ch].size())
                {
                    x = mp[ch][z];
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};