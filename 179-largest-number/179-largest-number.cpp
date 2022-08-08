class Solution {
public:
    static bool cmp(int a, int b){
        string a1 = to_string(a);
        string b1 = to_string(b);
        return (a1+b1)>(b1+a1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans;
        if(nums[0]==0)
            return "0";
        for(int x: nums)
            ans+=to_string(x);
        return ans;
    }
};