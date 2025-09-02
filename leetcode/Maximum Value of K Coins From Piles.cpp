class Solution {
public:
    int solve(vector<vector<int>>& piles,int k,int row,int col,vector<vector<vector<int>>> &dp){
        if(k<=0){
            return 0;
        }
        if(dp[row][col][k]!=-1)return dp[row][col][k];
        int samerow =  piles[row][col] ;
        if(col+1<=piles[row].size()-1)
          samerow += solve(piles,k-1,row,col+1,dp);
        int diffrow = piles[row][col];
        int nottake = 0;
        if(row+1<=piles.size()-1){
           diffrow += solve(piles,k-1,row+1,0,dp); 
           nottake = solve(piles,k,row+1,0,dp);

        }
        return dp[row][col][k] = max({samerow,diffrow,nottake});

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int maxcol = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            int col = piles[i].size();
            maxcol = max(maxcol,col);
        }
        vector<vector<vector<int>>> dp(piles.size(),vector<vector<int>>(maxcol+1,vector<int>(k+1,-1)));
        return solve(piles,k,0,0,dp);
        return 0 ; 
    }
};
