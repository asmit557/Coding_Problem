class Solution {
public:
    int maxProduct(vector<int>& nums) {
     long long int  suffix = 1;
     long long int  prefix = 1;
      long long int maxi = INT_MIN;
      int n = nums.size();
      for(int i=0;i<nums.size();i++){
              if(prefix==0){
                 prefix = 1;
              }
              if(suffix==0){
                 suffix = 1;
              }
               if(prefix > INT_MAX/nums[i] || prefix < INT_MIN/nums[i]) prefix = 1;
               if(suffix > INT_MAX/nums[i] || suffix < INT_MIN/nums[i]) suffix = 1;
              prefix = prefix*nums[i];
            suffix = suffix*nums[n-i-1];
            maxi = max(maxi,max(suffix,prefix));
      }
      maxi = int(maxi);
      return maxi;
    }
};
