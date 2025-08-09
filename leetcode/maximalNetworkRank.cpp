class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        vector<int> degree(n,0);
        for(auto i:roads){
            int u = i[0];
            int v = i[1];
            degree[u]++;
            degree[v]++;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                if(i!=j){
                   int ans = degree[i] + degree[j];
                   if(matrix[i][j]==1){
                    ans--;
                    maxi = max(maxi,ans);
                   }else{
                     maxi = max(maxi,ans);
                   }
                }
             }
        }
        return maxi;
    }
};
