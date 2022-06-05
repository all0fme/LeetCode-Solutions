class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans =0;
        for(char c: s)
        {
            if(c=='(')
            {
                st.push('(');
            }
            else{
                if(c==')')
                {
                    ans = max(ans,(int)st.size());
                    st.pop();
                }
            }
            
        }
        return ans;
        
    }
};