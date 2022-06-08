class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        int i=0,j = n-1;
        int flag=1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++,j--;
            }
            else{
                flag=0;
                break;
            }
        }
        if(flag)
            return 1;
        return 2;
        
    }
};