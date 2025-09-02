class Solution {
public:
    int solve(string &text1,string &text2,int m,int n,vector<vector<int>> &dp){
       if(m==0 || n==0) return 0;

       if(dp[m][n]!=-1)return dp[m][n];

       if(text1[m-1]==text2[n-1]){
          return dp[m][n] = 1 + solve(text1,text2,m-1,n-1,dp);
       }

       if(text1[m-1]!=text2[n-1]){
          return dp[m][n] = max(solve(text1,text2,m-1,n,dp),solve(text1,text2,m,n-1,dp));
       }
       return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        return solve(text1,text2,text1.length(),text2.length(),dp);
    }
};
