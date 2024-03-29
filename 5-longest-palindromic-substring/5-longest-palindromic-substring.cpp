class Solution {
public:
    int expand(string &s, int L,int R){
        while(L>=0 && R<s.size() && s[L]==s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
    string longestPalindrome(string s) {
        
        int n = s.size();
        int start =0,end=0;
        
        for(int i=0;i<n;i++)
        {
            int l1 = expand(s,i,i);
            int l2= expand(s,i,i+1);
            int len = max(l1,l2);
            if(len>(end-start+1)){
                start = i - (len-1)/2;
                end = i+ len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};