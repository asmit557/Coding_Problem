class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() , m= matrix[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<>> pq;
        for(int i = 0;i < n ; i++){
            pq.emplace(matrix[i][0],i,0);
        }
        int ans = INT_MIN;
        while(k--){
            auto [ele, row, col] = pq.top();
            // cout << ele << " " << row << " " << col << endl;
            if(k == 0) {
                ans = ele;
                break;
            }
            pq.pop();
            if(col < m-1){
                pq.emplace(matrix[row][col+1],row,col+1);
            }
        }
        return ans;
    }
};
