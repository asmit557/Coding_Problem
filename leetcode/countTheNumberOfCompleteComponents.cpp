class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj,int node,vector<int> &vis,int &cnt){
        vis[node]=1;
        cnt++;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(adj,i,vis,cnt);
            }
        }
    }
    bool dfscomponent(int &cnt,unordered_map<int,vector<int>> &adj,vector<int> &vis,int node,vector<int> &degree){
        vis[node]=1;
       for(auto i:adj[node]){
            if(!vis[i]){
                if(dfscomponent(cnt,adj,vis,i,degree)==false)return false;
            }
        }

        if(degree[node]==cnt-1){
            return true;
        }else{
            return false;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<int> degree(n,0);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        vector<int> vis1(n,0);
        vector<int> vis2(n,0);

        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis1[i]){
                int cnt = 0;
                dfs(adj,i,vis1,cnt);

                if(dfscomponent(cnt,adj,vis2,i,degree))ans++;
            }
        }
        return ans;
    }
};
