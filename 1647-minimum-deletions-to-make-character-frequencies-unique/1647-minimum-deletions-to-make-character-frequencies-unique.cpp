class Solution {
public:
    int minDeletions(string s) {
       
        
        vector<int> freq(26,0);
        unordered_map<int,int> mp;
        int del=0;
        for(char c: s)
        {
          freq[c-'a']++;
            
        }
        
        for(int i=0;i<26;i++)
            mp[freq[i]]++;
        sort(freq.begin(),freq.end(),greater<int>());
        for(auto x: freq)
        {
            if(mp[x]>1)
            {
                int num =x;
                while(num!=0 && mp[num]!=0)
                {
                    num--;
                    del++;
                }
                if(num>0)
                    mp[num]++;
                mp[x]--;
            }
           
        }
        return del;
        
    }
};