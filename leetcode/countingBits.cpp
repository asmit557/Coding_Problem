class Solution {
public:
    int solve(int n){
        int cnt = 0;
        while(n!=0){
            if(n&1){
                cnt++;
            }
            n = n>>1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
           int ones = solve(i); 
           ans.push_back(ones);
        }
        return ans;
    }
};
