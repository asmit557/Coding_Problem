class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:meetings){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int> vis(n,0);
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int>> > pq;
        pq.push({0,firstPerson});
        pq.push({0,0});

        vector<int> ans;
        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            vis[node] = 1;

            for(auto [neigh,edgetime]:adj[node]){
                 if(time <= edgetime && !vis[neigh]){
                    pq.push({edgetime,neigh});
                 }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
