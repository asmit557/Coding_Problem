class Solution {
public:
     void solve(vector<int> &nums,vector<int> v,set<vector<int>> &st,int index){
        if(index==nums.size()){
            st.insert(v);
            return ;
        }

        v.push_back(nums[index]);
        solve(nums,v,st,index+1);
        v.pop_back();
        solve(nums,v,st,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> v;
        solve(nums,v,st,0);
        vector<vector<int>> ans;
        for(auto i: st){
            ans.push_back(i);
        }
        return ans;
    }
};
