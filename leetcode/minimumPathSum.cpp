class Solution {
public:
     int solve(int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(m==0 && n==0) return grid[m][n];
        if(m<0 || n<0) return 1e9;
        if(dp[m][n]!=-1) return dp[m][n];
        int top = grid[m][n] + solve(m-1,n,dp,grid);
        int left = grid[m][n] + solve(m,n-1,dp,grid);
        return dp[m][n] = min(top,left);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
       
       int ans = solve(m-1,n-1,dp,grid); 
       return ans;
    }
};
