class Solution {
public:
    int solve(vector<int>& sat,int index,int time,vector<vector<int>> &dp){
       if(index>=sat.size()){
          return 0;
       }
       if(dp[index][time]!=-1)return dp[index][time];

       int take = time*sat[index] + solve(sat,index+1,time+1,dp);
       int nottake = solve(sat,index+1,time,dp);
       return dp[index][time] = max(take,nottake);
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        vector<vector<int>> dp(sat.size(),vector<int>(sat.size()+1,-1));
        return solve(sat,0,1,dp);
    }
};
