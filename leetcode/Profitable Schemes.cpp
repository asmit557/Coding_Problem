class Solution {
public:
int mod = 1e9 +7;
    int solve(int n,int minProfit, vector<int> &groups,vector<int> &profit,int currprofit,int index,vector<vector<vector<int>>> &dp){
        if(index>=groups.size()){
            if(currprofit>=minProfit){
                return 1;
            }else{
                return 0;
            }
        }
        

        if(dp[n][currprofit][index]!=-1)return dp[n][currprofit][index];
        
        int take = 0;
        if(n-groups[index]>=0)
          take = solve(n-groups[index],minProfit,groups,profit,min(minProfit,currprofit+profit[index]),index+1,dp);

        int nottake = solve(n,minProfit,groups,profit,min(minProfit,currprofit),index+1,dp);
        return dp[n][currprofit][index] = (take%mod + nottake%mod)%mod;  
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(minProfit+1,vector<int>(101,-1)));
        return solve(n,minProfit,group,profit,0,0,dp);
    }
};
