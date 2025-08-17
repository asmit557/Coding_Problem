class Solution {
public:
    int solve(vector<int>& piles,int left,int right,int turn,vector<vector<vector<int>>> &dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right][turn]!=-1)return dp[left][right][turn];
        if(turn){
            int chooseleft  = piles[left] + solve(piles,left+1,right,0,dp);
            int chooseright  = piles[right] + solve(piles,left,right-1,0,dp);
            return dp[left][right][turn] = max(chooseleft,chooseright);
        }
        else{
            int chooseleft  = -piles[left] + solve(piles,left+1,right,1,dp);
            int chooseright  = -piles[right] + solve(piles,left,right-1,1,dp);
            return dp[left][right][turn] = min(chooseleft,chooseright);
        }
    } 
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int left = 0;
        int right = n-1;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        int ans = solve(piles,left,right,1,dp);
        if(ans >0)return true;
        return false;
    }
};
