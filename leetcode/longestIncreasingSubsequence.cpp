class Solution {
public:
    int solve(vector<int>& nums,int index,int lastpick,vector<vector<int>> &dp){
           if(index < 0){
            return 0;
           }
           if(dp[index][lastpick]!=-1){
            return dp[index][lastpick];
           }
            int pick = INT_MIN;
           if(lastpick==nums.size() || nums[index] < nums[lastpick] ){
             pick = 1 + solve(nums,index-1,index,dp);
           }
           int notpick = solve(nums,index-1,lastpick,dp);
           return dp[index][lastpick] = max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int lastpick = nums.size();
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,nums.size()-1,lastpick,dp);
    }
};
