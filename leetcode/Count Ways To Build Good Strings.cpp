// recursion + memoisation
class Solution {
public:
    const int d = 1e9 + 7;
    #define ll long long

    vector<ll> dp;
    ll rec(ll low, ll high, ll zero, ll one, ll cnt) {
        // base
        if (cnt > high)
            return 0;

        //check
        if (dp[cnt] != -1)
            return dp[cnt];

        // solve
        ll ans = 0;
        if (cnt >= low) ans++;

        ans += rec(low, high, zero, one, cnt + zero);
        ans %= d;
        ans += rec(low, high, zero, one, cnt + one);
        ans %= d;
        
        return dp[cnt] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(high + 1, -1);
        return rec(low, high, zero, one, 0);
    }
};
