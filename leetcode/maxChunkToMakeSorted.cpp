class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int j = 0;
        int cnt = 0;
        int n = arr.size();
        int track[10] = {0};
        while(j<n){
           track[arr[j]] = 1;
           bool b = true;
           for(int i=0;i<=j;i++){
              if(track[i]==0){
                 b = false; 
              }
           }
           if(b){
             cnt++;
           }
           j++;
        }
        return cnt;
    }
};
