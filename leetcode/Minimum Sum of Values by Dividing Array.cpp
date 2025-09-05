class Solution {
public:
    int n;
    // int solve(vector<int> &nums,vector<int> &andValues,int index,int valueindex){
    //     if(valueindex==andValues.size() && index==nums.size())return 0;
    //     if(index==nums.size() || valueindex==andValues.size()) return 1e9;

    //     if(dp[index][valueindex]!=-1) return dp[index][valueindex]; 
    //     int currand =-1;

    //     int result = 1e9;

    //     for(int i=index;i<nums.size();i++){
    //        currand = currand & nums[i];
    //        if(currand==andValues[valueindex]){
    //           int ans = nums[i] + solve(nums,andValues,i+1,valueindex+1);
    //           result = min(result,ans);
    //        }
    //     }

    //     return dp[index][valueindex] = result; 

    // }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(andValues.size()+1,0));
        // int ans = solve(nums,andValues,0,0);
        for(int i=0;i<=andValues.size();i++){
            dp[nums.size()][i] = 1e9;
        }
        for(int i=0;i<=nums.size();i++){
            dp[i][andValues.size()] = 1e9;
        }
        dp[nums.size()][andValues.size()] = 0;

        for(int index=nums.size()-1;index>=0;index--){
            for(int valueindex=andValues.size()-1;valueindex>=0;valueindex--){

                int currand =-1;

                int result = 1e9;

                 for(int i=index;i<nums.size();i++){
                    currand = currand & nums[i];
                    if(currand==andValues[valueindex]){
                        int ans = nums[i] + dp[i+1][valueindex+1];
                        result = min(result,ans);
                    }
                 }

                   dp[index][valueindex] = result; 
            }
        }
        return dp[0][0]==1e9 ? -1 : dp[0][0];
    }
};
