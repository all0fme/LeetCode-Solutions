class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n= words.size();
        
        vector<vector<int>> mp(n,vector<int>(26,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                mp[i][words[i][j]-'a']++;
            }
        }
        unsigned long mx =0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int k=0;
                for(;k<26;k++)
                {
                    if(mp[i][k]>0 && mp[j][k]>0 )
                    {
                        break;
                    }
                }
                if(k==26)
                {
                    mx = max(mx,words[i].size()*words[j].size());
                }
            }
        }
        return mx;
        
    }
};