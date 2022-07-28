class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp1,mp2;
        
        for(char c: p)
            mp1[c]++;
        int l=0;
        int r = 0;
        vector<int> ans;
        
        while(r<s.size())
        {
            if(mp2[s[r]]<mp1[s[r]]){
                mp2[s[r]]++;
                r++;
                if((r-l)==p.size()){
                    ans.push_back(l);
                    mp2[s[l]]--;
                    l++;
                    
                }
            }
            else{
                if(l!=r){
                   
                    mp2[s[l]]--;
                    l++;
                
                }
                else{
                    l++;
                    r++;
                }
                
                
            }
        }
        return ans;
    }
};