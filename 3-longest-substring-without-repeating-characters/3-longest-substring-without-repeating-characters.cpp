class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // cout<<s[0]<<"\n";
        vector<int> a(256,0);
        int len =0;
       int i=0,j = 0;
        int n = s.size();
        while(j<n)
        {
            if(a[s[j]]==0)
            {
                a[s[j]]=1;
                j++;
                len = max(len,j-i);
            }
            else{
                
                a[s[i]]=0;
                i++;
            }
        }
        return len;
        
    }
};