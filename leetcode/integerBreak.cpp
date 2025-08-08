class Solution {
public:
    int solve(int n ,int lastpartition,int i, vector<vector<int>> &dp){
        if(i>n){
            return 1;
        }
        if(dp[i][lastpartition]!=-1)return dp[i][lastpartition];
        int pro = 0;
        int maxi = 0; 
        for(int j=i;j<=n;j++){
           pro = (j-lastpartition) * solve(n,j,j+1,dp);
           maxi = max(maxi,pro);
        }
        return dp[i][lastpartition] = maxi;
    }
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(n,0,1,dp);
    }
};
