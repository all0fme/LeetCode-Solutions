class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> freq(26,0);
        for(char c: magazine)
            freq[c-'a']++;
        for(char c: ransomNote)
            freq[c-'a']--;
        
        for(auto x: freq)
            if(x<0)
                return false;
        return true;
    }
};