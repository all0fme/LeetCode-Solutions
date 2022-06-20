class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> st(words.begin(),words.end());
        
        for(auto s: words){
            for(int i=1;i<s.size();i++)
                st.erase(s.substr(i));
        }
        
        int ans=0;
        
        for(auto s: st)
            ans+=s.size()+1;
        
        return ans;
        
        
    }
};