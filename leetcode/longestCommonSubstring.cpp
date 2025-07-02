class Solution {
  public:
  	vector<vector<int>>dp;
	int ans = 0;
    int longestCommonSubstr(string& s1, string& s2) {
        dp.resize(s1.length(), vector<int>(s2.length(), -1));
		solve(s1, s2, 0, 0);
		return ans;
    }
    int solve(string s1, string s2, int i, int j) {
		if(i >= s1.length() || j >= s2.length()) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		solve(s1, s2, i+1, j), solve(s1, s2, i, j+1);
		dp[i][j] = s1[i] == s2[j] ? solve(s1, s2, i+1, j+1) + 1 : 0;  // store the result for state (i, j) for future
		ans = max(ans, dp[i][j]);
		return dp[i][j];
	}
};
