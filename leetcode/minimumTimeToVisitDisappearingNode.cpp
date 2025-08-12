class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        adj.reserve(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dis(n, INT_MAX);
        dis[0] = 0;

        using P = pair<int,int>; // {distance, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();

            if (w > dis[node]) continue;               // Skip outdated
            if (w >= disappear[node]) continue;        // Node gone

            for (auto &[neigh, weight] : adj[node]) {
                int newDist = w + weight;
                if (newDist < dis[neigh] && newDist < disappear[neigh]) {
                    dis[neigh] = newDist;
                    pq.push({newDist, neigh});
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
            if (dis[i] < disappear[i]) ans[i] = dis[i];
        return ans;
    }
};
