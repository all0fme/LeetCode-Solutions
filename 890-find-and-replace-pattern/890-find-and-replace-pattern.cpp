class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char,char> mp1,mp2;
        int n = pattern.size();
        int flag;
        for(string s: words){
            mp1.clear();
            mp2.clear();
            if(s.size()==n){
                flag=1;
                for(int i=0;i<n;i++){
                    
                    if(mp1.find(pattern[i])==mp1.end() && mp2.find(s[i])==mp2.end()){
                        mp1[pattern[i]] = s[i];
                            mp2[s[i]]=pattern[i];
                    }
                    else if(mp1.find(pattern[i])!=mp1.end() && mp2.find(s[i])!=mp2.end() && mp1[pattern[i]]==s[i] && mp2[s[i]]==pattern[i]){
                        continue;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)
                ans.push_back(s);
        }
        return ans;
        
    }
};