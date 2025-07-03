class Solution {
public:
    int solve(int n, bool buy,int trans, vector<int> &prices,vector<vector<vector<int> > > &dp){
        if(n==prices.size()){
            return 0;
        }
        if(trans==0) return 0;
        if(dp[n][buy][trans]!=-1) return dp[n][buy][trans];
        if(buy){
            int buytake = -prices[n] + solve(n+1,0,trans-1,prices,dp);
            int notbuytake = solve(n+1,1,trans,prices,dp);
            return dp[n][buy][trans] = max(buytake,notbuytake);
        }
        if(!buy){
            int selltake = prices[n] + solve(n+1,1,trans-1,prices,dp);
            int notselltake = solve(n+1,0,trans,prices,dp);
            return dp[n][buy][trans] =  max(selltake,notselltake);
        }
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        bool buy = 1;
        vector<vector<vector<int> > > dp(
        prices.size(), vector<vector<int> >(2, vector<int>(2*k + 1, -1)));
         return solve(0,buy,2*k,prices,dp);
    }
};
