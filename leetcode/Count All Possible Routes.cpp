class Solution {
public:
int mod =1e9+7;
    int solve(vector<int>& locations, int start, int finish, int fuel,vector<vector<int>> &dp){
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        int result = 0;
        if(start==finish){
            result += 1;
        }
    
        for(int i=0;i<locations.size();i++){
            if(i!=start && fuel>= abs(locations[start]-locations[i])){
                result = (result + solve(locations,i,finish,fuel - abs(locations[start]-locations[i]),dp))%mod;
            }
        }
        return dp[start][fuel] = result%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(),vector<int>(201,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};
