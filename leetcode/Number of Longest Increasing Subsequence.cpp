class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> lis(n,1);
        vector<int> num(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && lis[j]+1>lis[i]){
                    lis[i] = lis[j]+1;
                    maxi = max(maxi,lis[i]);
                    num[i] = num[j];
                }
                else if(nums[j]<nums[i] && lis[j]+1==lis[i]){
                    num[i] += num[j]; 
                }
            }
        }


        int ans = 0;
        for(int i=0;i<n;i++){
            if(lis[i] == maxi){
                ans += num[i];
            }
        }
        return ans;
    }
};
