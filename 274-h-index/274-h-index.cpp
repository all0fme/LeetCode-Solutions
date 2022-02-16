class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        
        int h_index=0;
        int max_cit=100000;
        int papers=0;
        
        for(int i=citations.size()-1;i>=0;i--)
        {
            papers++;
            max_cit = min(max_cit,citations[i]);
            if(max_cit>=papers)
            {
                h_index= papers;
            }
        }
        return h_index;
        
    }
};