class Solution {
public:
    int solve(vector<int>& coins,int amount,int index,vector<vector<int>> &dp){
        if(index==0){
            if(amount % coins[index]==0){
                  return amount/coins[index];
            }
            else return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
         int pick = 1e9;
        if(amount >= coins[index])
           pick = 1 + solve(coins,amount-coins[index],index,dp);

        int notpick = solve(coins,amount,index-1,dp);
        return dp[index][amount] = min(pick,notpick);   
       
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
       if(solve(coins,amount,coins.size()-1,dp)==1e9) return -1;
       else return solve(coins,amount,coins.size()-1,dp);
    }
};
