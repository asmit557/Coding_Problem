class Solution {
public:
    int mod = 1e9+7;
    int solve(int index,string &s,int &k,vector<int> &dp){
        if(s[index]=='0')return 0;
        if(index>=s.length()){
            return 1;
        }

        if(dp[index]!=-1)return dp[index];
        int ans = 0;
        long long num = 0;
        for(int i=index;i<s.length();i++){
           num = num*10;
           num += s[i]-'0';
           if(num>k)return dp[index] = ans%mod;
           if(num<=(long long)k)
            ans = (ans + solve(i+1,s,k,dp))%mod;
        }
        return dp[index] = ans;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length()+1,-1);
        return solve(0,s,k,dp);
        // dp[s.length()] = 1;
        // for(int i=s.length();i>=0;i--){

        // int ans = 0;
        // long long num = 0;
        // for(int j=index;j<s.length();j++){
        //    num = num*10;
        //    num += s[j]-'0';
        //    if(num>k) dp[index] = ans%mod;
        //    else if(num<=(long long)k)
        //     ans = (ans + solve(j+1,s,k,dp))%mod;
        // }
        //  dp[index] = ans;
        // }
        // return dp[0];
    }
};
