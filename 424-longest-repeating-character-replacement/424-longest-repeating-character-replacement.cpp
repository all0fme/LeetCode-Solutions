class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        
        unordered_map<char,int> mp;
        int mf = 0;
        int i=0,j=0;
        int len =0;
        
        while(i<=j && j<n){
            
            mp[s[j]]++;
            mf = max(mf,mp[s[j]]);
            j++;
            
            if(j-i<=mf+k)
                len = max(j-i,len);
            else
            {
                mp[s[i]]--;
                i++;
                
            }
                
        }
        return len;
        
    }
};