class Solution {
public:
int solve(int index,int n,int k,vector<int> &arr, vector<int> &dp){
        if(index>=arr.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int maxi = 0;
        int result = 0;
        for(int i=index;i-index+1<=k && i<n ;i++){
             maxi = max(maxi,arr[i]);
             int ans = maxi*(i-index+1) + solve(i+1,n,k,arr,dp);
             result = max(ans,result);
        }
        return dp[index] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,k,arr,dp);
       
    }
};
