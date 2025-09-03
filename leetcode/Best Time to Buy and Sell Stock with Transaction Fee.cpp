class Solution {
public:
int solve(int n, bool buy, vector<int> &prices,vector<vector<int>> &dp,int fee){
        if(n==prices.size()){
            return 0;
        }
        
        if(dp[n][buy]!=-1) return dp[n][buy];
        if(buy){
            int buytake = -prices[n] + solve(n+1,0,prices,dp,fee);
            int notbuytake = solve(n+1,1,prices,dp,fee);
            return dp[n][buy] = max(buytake,notbuytake);
        }
        if(!buy){
            int selltake = prices[n] - fee + solve(n+1,1,prices,dp,fee);
            int notselltake = solve(n+1,0,prices,dp,fee);
            return dp[n][buy] =  max(selltake,notselltake);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices, int fee) {
        bool buy = 1;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,buy,prices,dp,fee);
    }
};
