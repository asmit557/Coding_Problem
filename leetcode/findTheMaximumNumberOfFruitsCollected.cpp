class Solution {
public:
    int solve2(vector<vector<int>>& fruits,int i,int j,int moves, vector<vector<int>> &dp2){
        if(i<0 || i>=fruits.size() || j>=fruits.size()){
            return -1e9;
        }
        if(i==fruits.size()-1 && j==fruits.size()-1 && moves==0){
            return 0;
        }
        if(moves==0){
            return -1e9;
        }
        
        if(dp2[i][j]!=-1) return dp2[i][j];

        int up = fruits[i][j] + solve2(fruits,i-1,j+1,moves-1,dp2);
        int right = fruits[i][j] + solve2(fruits,i,j+1,moves-1,dp2);
        int down = fruits[i][j] + solve2(fruits,i+1,j+1,moves-1,dp2);


        return dp2[i][j] = max({up,down,right});
    }
    int solve1(vector<vector<int>>& fruits,int i,int j,int moves,vector<vector<int>> &dp1){
        if(i>=fruits.size() || j<0 || j>=fruits.size()){
            return -1e9;
        }
        if(i==fruits.size()-1 && j==fruits.size()-1 && moves==0){
            return 0;
        }
        if(moves==0){
            return -1e9;
        }
        if(dp1[i][j]!=-1)return dp1[i][j];

        int left = fruits[i][j] + solve1(fruits,i+1,j-1,moves-1,dp1);
        int down = fruits[i][j] + solve1(fruits,i+1,j,moves-1,dp1);
        int right = fruits[i][j] + solve1(fruits,i+1,j+1,moves-1,dp1);


        return dp1[i][j] = max({left,down,right});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int sum = 0;
        for(int i=0;i<n;i++){
             sum += fruits[i][i];
             fruits[i][i] = 0;
        }
        vector<vector<int>> dp1(n,vector<int>(n,-1));
         vector<vector<int>> dp2(n,vector<int>(n,-1));
        sum += solve1(fruits,0,n-1,n-1,dp1);
        sum += solve2(fruits,n-1,0,n-1,dp2);
        return sum;
    }
};
