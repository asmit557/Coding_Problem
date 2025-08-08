class Solution {
public:
    bool static comp(vector<int> &v1 ,vector<int> &v2){
        return v1[1]<v2[1];
    }
    int solve(vector<vector<int>>& pairs,int i,int prev,vector<vector<int>> &dp){
        if(i>=pairs.size()){
            return 0;
        }
        if(prev!=-1 && dp[i][prev]!=-1)return dp[i][prev];
        int nottake = solve(pairs,i+1,prev,dp);
        int take = 0;
        if(prev==-1 || pairs[prev][1]<pairs[i][0]){
             take = 1 + solve(pairs,i+1,i,dp);
        }
        if(prev!=-1)dp[i][prev] = max(take,nottake); 
        return max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        vector<vector<int>> dp(pairs.size()+1,vector<int>(pairs.size()+1,-1));
        return solve(pairs,0,-1,dp);
    }
};
