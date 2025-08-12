class Solution {
public:
   bool dfsbool(vector<int> adj[],vector<int> &vis,unordered_map<int,int> &mp,int node){
      if(mp.find(node)!=mp.end()){
        return false;
      }
      
      vis[node]=1;
      for(auto i:adj[node]){
        if(!vis[i]){
            if(dfsbool(adj,vis,mp,i)==false){
                return false;
            };
        }
    }
    return true;
   }
   void dfs(int node,unordered_map<int,int> &mp,vector<int> adj[]){
      mp[node]++;
      for(auto i:adj[node]){
        if(mp.find(i)==mp.end()){
            dfs(i,mp,adj);
        }
      }
   }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        unordered_map<int,int> mp;
        vector<int> adj[n];

        for(auto i:in){
           int u = i[0];
           int v = i[1];
           adj[u].push_back(v);
        }
        dfs(k,mp,adj);
        vector<int> vis(n,0);
        bool b = true;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end() && !vis[i]){
                b = dfsbool(adj,vis,mp,i);
                if(!b){
                    break;
                }
            }
        }
        vector<int> ans;
        if(!b){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }else{
            for(int i=0;i<n;i++){
                if(mp.find(i)==mp.end())
                  ans.push_back(i);
            }
        }
        return ans;
    }
};
