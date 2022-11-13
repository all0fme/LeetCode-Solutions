class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string temp,ans;
        stack<string> st;
        while(str>>temp)
            st.push(temp);
        while(!st.empty())
        {
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
            
    }
};