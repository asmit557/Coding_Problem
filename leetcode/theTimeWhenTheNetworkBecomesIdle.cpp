class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
       int n = p.size();
       unordered_map<int,vector<int>> adj;
       for(auto i:edges){
          int u = i[0];
          int v = i[1];

          adj[u].push_back(v);
          adj[v].push_back(u);
       }

       vector<int> dist(n,1e9);
       vector<int> vis(n,0);
       dist[0] = 0;
       queue<pair<int,int>> pq;
       pq.push({0,0});
       vis[0] = 1;
       while(!pq.empty()){
            int node = pq.front().first;
            int distance = pq.front().second;
            dist[node] = distance;
            pq.pop();

            for(auto i:adj[node]){
               if(!vis[i]){
                 pq.push({i,distance+1});
                 vis[i] = 1;
               }
            }
       }
       for(int i=0;i<n;i++){
          cout<<dist[i]<<" ";
       }
        
       int maxi = 0;
       for(int i=1;i<n;i++){
         if(p[i]<2*dist[i]){
             int total = 2*dist[i];
             if(total%p[i]==0){
                 int c= total/p[i] - 1;
                 int ans = total + c*p[i];
                 maxi = max(maxi,ans+1);
             }else{
                  int c= total/p[i];
                  int ans = total + c*p[i];
                  maxi = max(maxi,ans+1);
             }
         }else{
            maxi = max(maxi,2*dist[i]+1);
         }
       }
       return maxi;
    }
};
