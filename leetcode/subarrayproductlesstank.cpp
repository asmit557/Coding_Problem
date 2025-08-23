class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int n = nums.size();
       if(k==0)return 0;
       int i=0;
       int j=0;
       int pro = 1;
       int cnt = 0;
       while(j<n){
        pro = pro*nums[j];
        while(pro>=k){
            pro /= nums[i];
            i++;
            if(i>j)break;
        }
        if(pro<k){
            cnt += j-i+1;
        }
        j++;
       }
       return cnt;
    }
};
