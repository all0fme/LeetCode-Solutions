class Solution {
public:
    string decodeString(string &s, int &i){
        
        string res;
        
        while(i<s.size() && s[i]!=']'){
            if(!isdigit(s[i]))
            res.push_back(s[i++]);
            else{
                int n =0;
                while(i<s.size() && isdigit(s[i])){
                    n = n*10 + (s[i++]-'0');
                }
                i++;
                string t =decodeString(s,i);
                i++;
                while(n--){
                    res+=t;
                }
                
            }
        }
        return res;
    }
    string decodeString(string s) {
        
        int i=0;
        return decodeString(s,i);
        
    }
};