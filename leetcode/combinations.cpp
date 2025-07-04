class Solution {
public:
    void solve(int n,int k, vector<vector<int>> &ans, vector<int> path,int index){
         if(k==0){
            ans.push_back(path);
            return;
         }
         if(index > n){
            return ;
         }
        for(int i = index;i<=n;i++){
            path.push_back(i);
            solve(n,k-1,ans,path,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        int index = 1;
        solve(n,k,ans,path,index);
        return ans;

    }
};
