class Solution {
public:
    int mod = 1e9+7;
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<n;i++){
            vector<int> v = conversions[i];
            adj[v[0]].push_back({v[1],v[2]});
        }
        vector<int> ans(n+1);
        ans[0] = 1;
        
        queue<pair<int,long long>> q;
        q.push({0,1});
        while(!q.empty()){
            int num = q.front().first;
            long long pro = q.front().second;
            q.pop();
            ans[num] = pro;
            for(auto i:adj[num]){
                long long result = ((pro%mod) * (i.second)%mod)%mod;
                q.push({i.first,result});
            }
        }
        
        
        
        
        
        return ans;
    }
};
