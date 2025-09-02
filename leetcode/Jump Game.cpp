class Solution {
public:
    bool solve(vector<int> &nums,int index,vector<int> &dp){
      if(index >= nums.size()-1) return true ;

      if(dp[index]!=-1)return dp[index];
      bool b = false;
      for(int i = index+1;i<=index + nums[index];i++){
          b = solve(nums,i,dp);
          if(b) return dp[index] =  true;
      }
      return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
