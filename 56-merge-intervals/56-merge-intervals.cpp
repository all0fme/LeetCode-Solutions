class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end());
        //vector<int> temp;
        int ptr1 =0;
        int ptr2=1;
        while(ptr1<=ptr2 && ptr1<n)
        {
            vector<int> temp;
            temp.push_back(intervals[ptr1][0]);
            int end = intervals[ptr1][1];
            while(ptr2<n && intervals[ptr2][0]<=end)
            {
                end = max(intervals[ptr2][1],end);
                ptr2++;
            }
            temp.push_back(end);
            ans.push_back(temp);
            ptr1=ptr2;
            ptr2++;
            
        }
        return ans;
    }
};