class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int n = heights.size();
        int ans =0;
        
        for(int i=1;i<n;i++)
        {
            if(heights[i]-heights[i-1] >0)
                pq.push(heights[i]-heights[i-1]);
            if(pq.size()>ladders)
            {
                int req_brick = pq.top();
                pq.pop();
                
                if(req_brick<=bricks)
                    bricks-=req_brick;
                else{
                    
                    break;
                }
                    
            }
            ans =i;
        }
       return ans;
        
    }
};