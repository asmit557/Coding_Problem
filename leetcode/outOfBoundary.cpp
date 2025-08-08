class Solution {
public:
    int mod = 1e9+7;
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
    int solve(int m,int n,int maxMove,int i,int j,vector<vector<vector<int>>> &dp){
        if((i>=m || i<0 || j>=n || j<0) && maxMove>=0){
            return 1;
        }
        if(maxMove<0){
            return 0;
        }
        if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove];

        int total = 0;
        for(int k=0;k<4;k++){
            int newRow = i + dr[k];
            int newCol = j + dc[k];
            total = (total + solve(m,n,maxMove-1,newRow,newCol,dp))%mod;
        }
        return dp[i][j][maxMove] = total%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};
