class Solution {
public:
    
    bool isVowel(char c)
    {
       vector<char> v ={'a','e','i','o','u','A','E','I','O','U'};
        for(char x: v)
        {
            if(x==c)
                return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        
      int i=0;
        int j = s.size()-1;
        while(i<j)
        {
            while(i<s.size() && !isVowel(s[i]))
                i++;
            while(j>=0 && !isVowel(s[j]))
                j--;
            if(i<j)
                swap(s[i++],s[j--]);
        }
        return s;
        
    }
};