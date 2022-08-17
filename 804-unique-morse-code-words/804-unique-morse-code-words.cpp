class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> mp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for(auto word: words)
        {
            string temp;
            
            for(char c: word)
            {
                temp+=mp[c-'a'];
            }
            st.insert(temp);
        }
        return st.size();
        
    }
};