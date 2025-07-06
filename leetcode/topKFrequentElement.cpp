class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int,int> m;
      for(int i=0;i<nums.size();i++){
          m[nums[i]]=0;
      }  
       for(int i=0;i<nums.size();i++){
          m[nums[i]]++;
      }  
      vector<pair<int,int>> ans;
     for(auto i :m){
             ans.push_back(make_pair(i.second,i.first));
     }
     sort(ans.begin(),ans.end());
     vector<int> ans1;
     int i=1;
     while(k--){
       
        int l = ans.size()-i;
        ans1.push_back(ans[l].second);
        i++;
     }
     return ans1;
    }
};
