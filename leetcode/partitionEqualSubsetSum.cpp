bool equalPartition(vector<int>& arr) {
        // Similar to 0-1 Knapsack problem
        // If sum is odd then there can't be 2 partitions with equal sum
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if(sum % 2 != 0) {
            return false;
        }
        sum = sum/2; // Sum of one partition
        vector<vector<bool>>dp(n+1, vector<bool>(sum+1));
        
        // Base case
        for(int j = 0; j <= sum; j++) {
            dp[0][j] = false;
        }
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        //Choice diagram
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(arr[i-1] <= j) {
                    bool pick = dp[i-1][j - arr[i-1]];
                    bool not_pick = dp[i-1][j];
                    dp[i][j] = pick | not_pick;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
