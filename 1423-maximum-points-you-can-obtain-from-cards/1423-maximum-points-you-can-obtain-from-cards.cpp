class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int window = n-k;
        int sum=0;
        for(int i=0;i<window;i++)
        {
            sum+=cardPoints[i];
        }
        int nsum= sum;
        for(int i=window;i<n;i++)
        {
            nsum = nsum-cardPoints[i-window] + cardPoints[i];
            sum = min(sum,nsum);
        }
        return accumulate(cardPoints.begin(),cardPoints.end(),0)-sum;
        
    }
};