class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> matrix(n+1,vector<int>(n+1,1e8));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j+1 ||j==i+1){
                    matrix[i][j] = 1;
                }
                if(i==j){
                    matrix[i][j]=0;
                }
            }
        }
        if(x!=y){
        matrix[x][y]=1;
        matrix[y][x]=1;
        }
       

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        vector<int> ans(n,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i][j]>0 && matrix[i][j]<=n){
                    ans[matrix[i][j]-1]++;
                }
            }
        }
        return ans;
    }
};
