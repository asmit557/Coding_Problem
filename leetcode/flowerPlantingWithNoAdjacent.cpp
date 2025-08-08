class Solution {
public:
    bool issafe(int vertex, int col, unordered_map<int,vector<int>> &adj, vector<int> &color) {
    for (auto it : adj[vertex]) {
        // If adjacent vertex has the same color, not safe
        if (color[it-1] != -1 && col == color[it-1])
            return false;
    }
    return true;
}
    bool cancolor(int vertex, int m, unordered_map<int,vector<int>> &adj, vector<int> &color) {
    // If all vertices are colored successfully
    if (vertex == color.size())
        return true;

    // Try all colors from 0 to m-1
    for (int i = 1; i <= m; i++) {
        if (issafe(vertex, i, adj, color)) {
            color[vertex-1] = i; 
            if (cancolor(vertex + 1, m, adj, color))
                // If the rest can be colored, return true
                return true; 
            color[vertex-1] = -1; 
        }
    }
    
    // No valid coloring found
    return false; 
}
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    unordered_map<int,vector<int>> adj;

    // Build adjacency list from edges
    for (auto it : paths) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]); 
    }
    vector<int> color(n+1, -1); 
    cancolor(1, 4, adj, color);
    color.pop_back();
    return color;
    }
};
