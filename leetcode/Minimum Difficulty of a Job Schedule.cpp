class Solution {
public:
    int solve(int index,vector<int>& jd,int d,vector<vector<int>> &dp){
       if(d==1){
         int maximum = 0;
         for(int i=index;i<jd.size();i++){
            maximum = max(maximum,jd[i]);
         }
         return maximum;
       }
       if(dp[index][d]!=-1)return dp[index][d];
       
       int maxi = 0;
       int mini = 1e9;
       for(int i=index;i<=jd.size()-d;i++){
           maxi = max(maxi,jd[i]);
           int nextday = solve(i+1,jd,d-1,dp);
           mini = min(mini,maxi + nextday);
       }
       return dp[index][d]=mini;

    }
    int minDifficulty(vector<int>& jd, int d) {
        if(jd.size()<d)return -1;
        int n = jd.size();
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
       return solve(0,jd,d,dp);
    }
};
