class Solution {
public:
int solve(vector<int>& days,vector<int>& costs,int index,int travel,vector<vector<int>> &dp){
    if(travel >= days[days.size()-1]) return 0;
    if(travel >= days[index]){
        return solve(days,costs,index+1,travel,dp);
    }
    if(dp[index][travel]!=-1) return dp[index][travel];
    int day1 = costs[0] + solve(days,costs,index+1,days[index] + 1 -1,dp);
    int day7 = costs[1] + solve(days,costs,index+1,days[index] + 7 - 1,dp);
    int day30 = costs[2] + solve(days,costs,index+1,days[index] + 30 - 1,dp);

    return dp[index][travel] = min(day1,min(day7,day30));
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(),vector<int>(days[days.size()-1] + 1,-1));
        return solve(days,costs,0,0,dp);
    }
};
