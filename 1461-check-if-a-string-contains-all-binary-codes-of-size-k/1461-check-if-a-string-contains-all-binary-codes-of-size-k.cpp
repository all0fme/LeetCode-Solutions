class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        
        int reqSize = (1<<k);
        if(k>s.size())
            return false;
        
        for(int i=0;i<s.size()-k+1;i++)
        {
            string str;
            for(int j=i;j<i+k;j++){
                str.push_back(s[j]);
                
            }
            st.insert(str);
        }
        return st.size()==reqSize;
        
    }
};