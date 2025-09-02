class Solution {
public:
    int solve(vector<int>& prices,int buy,int index, vector<vector<int>> &dp){
       if(index>=prices.size()){
        return 0;
       }
       if(dp[index][buy]!=-1)return dp[index][buy];

       if(buy){
          int take = -prices[index] + solve(prices,0,index+1,dp);
          int nottake = solve(prices,1,index+1,dp);
          return dp[index][buy] = max(take,nottake);
       }else{
         int take = prices[index] + solve(prices,1,index+2,dp);
         int nottake = solve(prices,0,index+1,dp);
         return dp[index][buy] = max(take,nottake);
       }
       return 0;

    }
    int maxProfit(vector<int>& prices) {
        int buy = 1;
        int index = prices.size()-1; 
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,buy,0,dp);
    }
};
