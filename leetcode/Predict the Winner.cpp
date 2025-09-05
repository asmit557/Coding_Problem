class Solution {
public:
    int solve(vector<int>& nums,int left,int right,int turn, vector<vector<vector<int>>> &dp){
    if(left>right) return 0;
    
    if(dp[left][right][turn]!=-1)return dp[left][right][turn];
    if(turn==0){
      int first = nums[left] + solve(nums,left+1,right,1,dp);
      int last = nums[right] + solve(nums,left,right-1,1,dp);
      return dp[left][right][turn] = max(first,last);
    }else{
        int first = -nums[left] + solve(nums,left+1,right,0,dp);
        int last = -nums[right] + solve(nums,left,right-1,0,dp);
        return dp[left][right][turn] = min(first,last);
    }
       return 0;
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(nums.size()+1,vector<int>(2,-1)));
        int ans = solve(nums,0,nums.size()-1,0,dp);
        if(ans>=0)return true;
        return false;
    }
};
