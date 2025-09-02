class Solution {
public:
    int solve(vector<int> &nums,vector<int> &dp,int n){
       if(n<0)return 0;
       
       if(dp[n]!=-1)return dp[n];
       int take = nums[n] + solve(nums,dp,n-2);
       int nottake = solve(nums,dp,n-1);
       return dp[n]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,dp,nums.size()-1);
    }
};
