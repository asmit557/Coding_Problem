class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        set<pair<int,int>> st;
        int cnt = 0;
        for(int i=0;i<n;i++){
           mp[nums[i]]--;
           if(mp[nums[i]]==0){
              mp.erase(nums[i]);
           }
           if(mp.find(nums[i]+k)!=mp.end()){
              st.insert({nums[i],nums[i]+k});
           }
           if(mp.find(nums[i]-k)!=mp.end()){
               st.insert({nums[i]-k,nums[i]});
           }
        }
        return st.size();
    }
};
