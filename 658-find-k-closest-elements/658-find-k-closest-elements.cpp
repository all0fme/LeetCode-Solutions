class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int sum =0;
        int n = arr.size();
        
        for(int i=0;i<k;i++)
        {
            sum+=abs(arr[i]-x);
        }
        int ind = 0;
        int tempsum=sum;
        //cout<<n-k+1<<"\n";
        for(int i=k;i<n;i++)
        {
           // cout<<tempsum<<"\n";
            tempsum-=abs(arr[i-k]-x);
            tempsum+=abs(arr[i]-x);
            
            if(tempsum<sum)
            {
                sum = tempsum;
                ind = i-k+1;
            }
        }
        vector<int> ans;
        for(int i=ind;i<ind+k;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};