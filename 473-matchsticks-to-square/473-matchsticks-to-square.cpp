class Solution {
public:
   int dp[5][1<<16];
 bool dfs(vector<int>& nums, int pos, int sum,int mask, int target, int k) {
	//when k==1 we can always divide the array in single parts so return true
	 if (k == 1) return true;
	 if(dp[k][mask]!=-1)return dp[k][mask];//if we calculated the answer before, the return answer, no need to calculate further
	 //if current sum is equal to the (target=totalsum/4) then one part is found so check if
	 //remaining array can be divided in k-1 parts and also change the sum to zero
	if (sum == target) return dfs(nums, 0, 0,mask, target, k-1);
	if (pos== nums.size()) return false;
	for (int i=pos; i<nums.size(); i++) {
		//mask&(1<<i) checks if the set bit is 1, meaning the element is present the set
		if (mask&(1<<i) && sum + nums[i] <= target)
		{
			//now as we chosen the current i'th element so set the i'th bit to zero, and the way to do is mask^(1<<i)
			if (dfs(nums, i+1, sum+nums[i],mask^(1<<i), target, k))
				return dp[k][mask]=true;
		}
	}
	return dp[k][mask]=false;//store the value 
}
//given array where we have to divide the array in k equal parts and here k=4
bool makesquare(vector<int>& nums) {
	if (!nums.size()) return false;//if array size is zero square can'tbe made
	int sum = 0;
	for (auto i : nums) sum += i;
	if (sum % 4 != 0) return false;//sum should be divisible by 4, as all sides must be equal
	memset(dp,-1,sizeof(dp));//initializing dp with -1
	return dfs(nums, 0, 0,(1<<nums.size())-1,sum/4, 4);
}
};