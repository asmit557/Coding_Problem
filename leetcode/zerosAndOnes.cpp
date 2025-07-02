class Solution {
public:
    int dp[600][101][101];
    int countz(string s){
        int count = 0;
        for(auto i : s){
            if(i == '0') count++;
        }
        return count;
    }
    int fun(vector<string>& strs, int i, int m, int n){
        // cout << i << " " << m << " " << n << endl;
        if(i >= strs.size()) return 0;
        if(dp[i][m][n] !=  -1) return dp[i][m][n];
        int zero = countz(strs[i]);
        int ones = strs[i].size() - zero;
        int ans = fun(strs,i+1,m,n);
        if(zero <= m and ones <= n){
            ans = max(ans,1+fun(strs,i+1,m-zero,n-ones));
        }
        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // cout << strs.size() << endl;
        memset(dp,-1,sizeof(dp));
        return fun(strs,0,m,n);
    }
};
