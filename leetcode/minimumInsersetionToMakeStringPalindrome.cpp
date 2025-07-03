class Solution {
public:
    int minInsertions(string A) {
        string str1 = A;
        string str2 = "";
        for(int i=str1.length()-1;i>=0;i--){
            str2 += str1[i];
        }
        vector<vector<int>> dp(A.length()+1,vector<int>(A.length()+1,0));
        // return solve(n-1,m-1,str1,str2,dp);
        
        for(int i=1;i<=A.length();i++){
            for(int j=1;j<=A.length();j++){
                if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return A.length() - dp[A.length()][A.length()];
    }
};
