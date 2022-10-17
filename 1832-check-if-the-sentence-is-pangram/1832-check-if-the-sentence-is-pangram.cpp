class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int> freq(26);
        
        for(char c: sentence)
            freq[c-'a']++;
        for(int f: freq)
            if(f==0) return false;
        return true;
        
    }
};