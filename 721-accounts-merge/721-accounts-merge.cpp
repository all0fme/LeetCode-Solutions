class Solution {
public:
    vector<int> dsu;
    
    int find_par(int x){
        if(dsu[x]!=x)
        {
            return dsu[x] = find_par(dsu[x]);
        }
        return x;
    }
    void union_par(int a, int b){
        a = find_par(a);
        b = find_par(b);
        if(a!=b){
            dsu[b]=a;
        }
    }
    unordered_map<string,int> mp;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        dsu.resize(n);
        for(int i=0;i<n;i++)
            dsu[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++){
                
                if(mp.find(accounts[i][j])!=mp.end()){
                    union_par(mp[accounts[i][j]],i);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }
        unordered_map<int,set<string>> mp2;
        for(int i=0;i<n;i++)
        {
            if(dsu[i]==i)
            {
                
                for(int j=1;j<accounts[i].size();j++)
                {
                     mp2[i].insert(accounts[i][j]);
                }
                
            }
            else{
                 for(int j=1;j<accounts[i].size();j++)
                {
                    mp2[find_par(i)].insert(accounts[i][j]);
                }
            }
        }
        vector<vector<string>> ans;
        
        for(auto &it: mp2){
            vector<string> temp;
            temp.push_back(accounts[it.first][0]);
            for(auto it2: it.second){
                temp.push_back(it2);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};