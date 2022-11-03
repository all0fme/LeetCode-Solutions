class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int odd=0;
        int len =0;
        for(string s: words)
        {
           
                mp[s]++;
        }
        for(auto &x: mp)
        {
            string temp;
            temp.push_back(x.first[1]);
            temp.push_back(x.first[0]);
            if(temp[0]==temp[1])
            {
                if(x.second%2)
                {
                    odd=1;
                    len+=2*(x.second-1);
                }
                else
                    len+=2*(x.second);
            }
            else if(mp.find(temp)!=mp.end())
                len+=2*min(x.second,mp[temp]);
        }
        if(odd)
            len+=2;
        return len;
    }
};