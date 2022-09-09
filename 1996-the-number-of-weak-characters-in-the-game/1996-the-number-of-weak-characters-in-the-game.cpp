class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
       vector<int> vec(100002,0);
        
        for(auto &x: properties)
        {
            vec[x[0]] = max(x[1],vec[x[0]]);
        }
        for(int i = 100000;i>=0;i--)
        {
            vec[i] = max(vec[i+1],vec[i]);
        }
        int ans=0;
        for(auto &x: properties){
            
            if(vec[x[0]+1]>x[1])
            {
                ans++;
            }
        }
        return ans;
        
        
        
        
        
    }
};