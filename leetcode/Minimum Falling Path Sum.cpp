class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(row==matrix.size()-1){
            return matrix[row][col];
        }

        if(dp[row][col]!=-1)return dp[row][col];
        int left = 1e9;
        if(col-1>=0){
            left = matrix[row][col] + solve(row+1,col-1,matrix,dp);
        }
        
        int down = matrix[row][col] + solve(row+1,col,matrix,dp);
        int right = 1e9;
        if(col+1<=matrix[0].size()-1)
           right = matrix[row][col] + solve(row+1,col+1,matrix,dp);

        return dp[row][col]=min({left,right,down});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // for(int i=0;i<n;i++){
        //    mini = min(mini,solve(0,i,matrix,dp));
        // }
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<m;i++){
            for(int j=0;j<n;j++){
                int down = matrix[i][j] + dp[i-1][j] ;
                int left = matrix[i][j];
                if(j-1>=0) left += dp[i-1][j-1];
                else left += 1e9;
                int right = matrix[i][j];
                if(j+1<n) right += dp[i-1][j+1];
                else right += 1e9;

                dp[i][j] = min(min(down,left),right);
            }
        }
       int mini = 1e9;
        for(int i=0;i<n;i++){
           mini = min(mini,dp[m-1][i]);
        }
        return mini;
    }
};
