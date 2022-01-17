class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> list;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]==' ')
            {
                list.push_back(str);
                str="";
                
            }
            else
                str+=s[i];
            
        }
        list.push_back(str);
        for(string st:list)
            cout<<st<<"\n";
        if(list.size()!=pattern.size())
            return false;
        unordered_map<char,string> mp;
        unordered_map<string,char> mp2;
        for(int i=0;i<list.size();i++)
        {
            if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=list[i])
                    return false;
            }
            else
            {
                if(mp2.find(list[i])==mp2.end())
                mp[pattern[i]]=list[i],mp2[list[i]]=pattern[i];
                else
                    return false;
            }
                
        }
        return true;
        
        
    }
};