class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        int ind = 0;
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            ind++;
            if(ind ==1)
                ans[temp.second] = "Gold Medal";
            else if(ind==2)
            {
                 ans[temp.second] = "Silver Medal";
            }
            else if(ind==3)
            {
                 ans[temp.second] = "Bronze Medal";
            }
            else{
                 ans[temp.second] = to_string(ind);
            }
        }
        return ans;
    }
};