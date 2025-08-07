class Solution {
public:
    int solve(int n,int cnt,int copylast,vector<vector<int>> &dp){
        if(cnt>n){
            return 1e9;
        }
        if(cnt==n){
            return 0;
        }
        if(dp[cnt][copylast]!=-1)return dp[cnt][copylast];
        int paste = 1e9;
       if(copylast!=0)
        paste = 1 + solve(n,cnt+copylast,copylast,dp);

       int copy = 1e9;
       if(cnt!=copylast)
        copy = 1 + solve(n,cnt,cnt,dp);

       return dp[cnt][copylast] = min(copy,paste);
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(n,1,0,dp);
    }
};
