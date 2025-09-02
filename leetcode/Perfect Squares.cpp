class Solution {
public:
    int solve(int n, vector<int> &dp){
       if(n==0)return 0;

       if(dp[n]!=-1)return dp[n];
       int mini = 1e9;
       for(int i=1;i*i<=n;i++){
          int ans = 1 + solve(n-i*i,dp);
          mini = min(mini,ans);
       }
       return dp[n] = mini;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp); 
    }
};
