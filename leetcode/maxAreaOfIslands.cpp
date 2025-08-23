class Solution {
public:
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    int m;
    int n;
    bool isValid(int row,int col){
        if(row>=0 && col>=0 && row<m && col<n){
            return true;
        }
        return false;
    }
    void dfs(int row,int col,int &cnt,vector<vector<int>>& grid,vector<vector<int>>& vis){
         vis[row][col] = 1;
         cnt++;
        for(int i=0;i<4;i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(isValid(nrow,ncol) && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,cnt,grid,vis);
            } 
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    if(grid[i][j]==1 && vis[i][j]==0){
                        int cnt = 0;
                        dfs(i,j,cnt,grid,vis);
                        ans = max(ans,cnt);
                    }  
            }
        } 
        return ans; 
    }
};
