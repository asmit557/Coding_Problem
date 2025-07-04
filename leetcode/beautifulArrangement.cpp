class Solution {
private:
    int solve(int ind, int n, vector<int>& vis) {
        if (ind > n) {
            return 1;
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && (i % ind == 0 || ind % i == 0)) {
                vis[i] = 1;
                cnt += solve(ind + 1, n, vis);
                vis[i] = 0;
            }
        }
        return cnt;
    }

public:
    int countArrangement(int n) {
        vector<int> vis(n + 1, 0);
        return solve(1, n, vis);
    }
};
