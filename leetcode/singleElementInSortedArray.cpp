class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size()-2;
        int mid;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-2]!=nums[nums.size()-1]){
            return nums[nums.size()-1];
        }
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return 0;
    }
};
