class Solution {
public:
    int dr[8] = {-2,-1,1,2,-2,-1,1,2};
    int dc[8] = {1,2,2,1,-1,-2,-2,-1};
     double solvein(int n ,int k,int row,int col,vector<vector<vector<double>>> &dp){
        if(row<0 || row>=n || col<0 || col>=n){
            return 0;
        }
        if(k==0){
            return 1;
        }

        if(dp[k][row][col]!=-1.0)return dp[k][row][col];
        double result = 0;
        for(int i=0;i<8;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            result += solvein(n,k-1,nrow,ncol,dp);
        }
        return dp[k][row][col] = double(result)/double(8);
    }
    
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n+1,vector<double>(n+1,-1.0)));
        double in = solvein(n,k,row,col,dp);
        return in;
    }
};
