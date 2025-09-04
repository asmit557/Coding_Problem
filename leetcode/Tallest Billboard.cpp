class Solution {
public:
    int solve(vector<int>&rods,int i,int diff,vector<vector<int>> &dp){
        if(i>=rods.size()){
            if(diff==0)return 0;
            else return -1e9;
        }
        if(dp[i][diff+5001]!=-1)return dp[i][diff+5001];

        int opt1 = rods[i] + solve(rods,i+1,diff+rods[i],dp);
        int opt2 = solve(rods,i+1,diff-rods[i],dp);
        int opt3 = solve(rods,i+1,diff,dp);

        return dp[i][diff+5001] = max({opt1,opt2,opt3});

    } 
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += rods[i];
        }
        int half = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(10001,-1));
        return solve(rods,0,0,dp);
       
    }
};
