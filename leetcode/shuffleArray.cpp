class Solution {
public: 
    vector<int> temp;
    Solution(vector<int>& nums) {
        temp = nums;
    }
    
    vector<int> reset() {
        return temp;
    }
    
    vector<int> shuffle() {
        vector<int> ans = temp;
        random_shuffle(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
