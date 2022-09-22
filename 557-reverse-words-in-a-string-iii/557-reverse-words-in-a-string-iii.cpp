class Solution {
public:
    string reverseWords(string s) {
        
        stringstream str(s);
        
        string word;
        string ans;
        
        while(str>>word)
        {
            reverse(word.begin(),word.end());
            if(ans.size())
                ans+=" ";
            ans+=word;
        }
        
        
        return ans;
        
    }
};