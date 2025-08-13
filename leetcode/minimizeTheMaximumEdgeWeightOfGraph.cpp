class Solution {
public:
    
    bool check(vector<vector<pair<int,int>>> &adj,int weight,int n,vector<int> &vis){
        
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int count = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &[neigh, edgeweight] : adj[node]) {
                if (edgeweight <= weight && !vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                    if (++count == n) return true; // all reachable
                }
            }
        }
        return count == n;


    } 
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int maxew = 0;
        int minew = 1e6;
       vector<vector<pair<int, int>>>  adj(n);
        for(auto i:edges){
           maxew = max(maxew,i[2]);
           minew = min(minew,i[2]);
           int u = i[0];
           int v = i[1];
           adj[v].push_back({u,i[2]});
        }

        
        int left = minew ;
        int right = maxew;
        int ans = -1;
        while(left<=right){
            int mid = (left+right)/2;
            vector<int> vis(n,0);
            if(check(adj,mid,n,vis)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
