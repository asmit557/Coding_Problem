class Solution {
public:
   vector<vector<int>> dp;
   vector<int> next;
    int solve(vector<vector<int>> &events,int i,int k){
        if(i>=events.size()){
            return 0;
        }
        if(k<=0){
            return 0;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        
        

        int take = events[i][2] + solve(events,next[i],k-1);
        int nottake = solve(events,i+1,k);

        return dp[i][k] = max(take,nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int  n = events.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));
        next.assign(n, n);
         for(int i=0; i<n; i++){
            next[i]=upper_bound(events.begin()+i, events.end(), vector<int>{events[i][1]+1,0,0})-events.begin();
        }
        return solve(events,0,k);
    }
};
