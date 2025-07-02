class Solution {
  public:
    
  
    unordered_map<int, vector<int>> vali = {
        {1, {1,2, 4}},       // Assuming 1 is top-left: right (2), down (4)
        {2, {2,1, 3, 5}},    // 2 connects to left (1), right (3), down (5)
        {3, {3,2, 6}},       // 3 connects to left (2), down (6)
        {4, {4,1, 5, 7}},    // 4 connects to up (1), right (5), down (7)
        {5, {5,2, 4, 6, 8}}, // 5 connects to all 4 directions
        {6, {6,3, 5, 9}},    // 6 connects to up (3), left (5), down (9)
        {7, {7,4, 8}},       // 7 connects to up (4), right (8)
        {8, {8,5, 7, 9,0}},    // 8 connects to left (7), up (5), right (9)
        {9, {9,6, 8}},
        {0, {0,8}}     
    };
    
    
    int dfs(int el , int left){
        if(left == 0){
            return 1;
        }
        
        int ans=0;
        for(auto nbr: vali[el]){
            ans+= dfs(nbr, left-1);
        }
        return ans;
    }
    int getCount(int n) {
        
        int cnt=0;
        for(int i=0;i<=9;i++){
            // consider curr -> left = ( n-1)
            int el = i;
            int left = n-1;
            cnt+=dfs(el , left);
        }
        
        return cnt;
        
    }
};
