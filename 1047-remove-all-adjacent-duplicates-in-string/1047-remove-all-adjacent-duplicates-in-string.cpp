class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() || s[i]!=st.top())
                st.push(s[i]);
            else
                st.pop();
        }
        string ss;
        while(!st.empty()){
            ss.push_back(st.top());
            st.pop();
        }
        reverse(ss.begin(),ss.end());
        return ss;
    }
};