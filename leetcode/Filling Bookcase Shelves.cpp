class Solution {
public:
    int solve(vector<vector<int>> books,int shelfwidth,int index,vector<int> &dp){
        if(index>=books.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int currwidth = 0;
        int result = 1e9;
        int maxi = 0;
        for(int i=index;i<books.size();i++){
            if(currwidth + books[i][0]<=shelfwidth){
                currwidth += books[i][0];
                maxi = max(maxi,books[i][1]);
                int ans = maxi + solve(books,shelfwidth,i+1,dp);
                result = min(result,ans);
            }else{
                break;
            }
        }
        return dp[index] = result;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfwidth) {
        vector<int> dp(books.size()+1,-1);
        return solve(books,shelfwidth,0,dp);
    }
}; 
