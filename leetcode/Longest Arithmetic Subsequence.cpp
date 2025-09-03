class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<vector<int>> t(n,vector<int>(1002,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                t[i][diff+501] = t[j][diff+501]>0 ? t[j][diff+501]+1:2;
                maxi = max(maxi,t[i][diff+501]);
            }
        }
        return maxi;
    }
};
