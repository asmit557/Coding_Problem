class Solution {
public:
     int solve(int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){
       if(m==grid.size()-1 && n==grid[0].size()-1){
          return grid[m][n];
       }
       if(dp[m][n]!=-1)return dp[m][n];
       int down = 1e9;
       if(m+1<=grid.size()-1)
        down = grid[m][n] + solve(m+1,n,dp,grid);

       int right = 1e9;
       if(n+1<=grid[0].size()-1)
         right = grid[m][n] + solve(m,n+1,dp,grid);

       return dp[m][n] = min(down,right);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
       
       return solve(0,0,dp,grid); 
    }
};
