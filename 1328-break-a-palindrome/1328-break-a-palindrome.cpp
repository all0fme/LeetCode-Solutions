class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string ans;
        if(n==1)
            return ans;
        if(n%2)
        {
            for(int i=0;i<n;i++)
            {
                if(i==n-1)
                {
                    if(palindrome[i]=='a'){
                        palindrome[i]='b';
                        break;
                    }
                }
                if(i!=n/2 && palindrome[i]!='a')
                {
                    palindrome[i] = 'a';
                    break;
                }
            }
        }
        else{
            for(int i=0;i<n;i++)
            {
                if(i==n-1)
                {
                   if(palindrome[i]=='a'){
                        palindrome[i]='b';
                        break;
                    }
                }
                if(palindrome[i]!='a')
                {
                    palindrome[i] = 'a';
                    break;
                }
            }
        }
        return palindrome;
    }
};