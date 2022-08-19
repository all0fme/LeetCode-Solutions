class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> fm,hm;
        
        for(int x: nums)
            fm[x]++;
        for(int x: nums)
        {
            
            if(fm[x]==0)
                continue;
            if(hm[x]>0)
            {
                hm[x]--;
                fm[x]--;
                hm[x+1]++;
            }
            else
            {
                fm[x]--;
                fm[x+1]--;
                fm[x+2]--;
                hm[x+3]++;
            }
            
        }
        for(auto x : fm)
        {
            if(x.second!=0)
                return false;
        }
        return true;
    }
};