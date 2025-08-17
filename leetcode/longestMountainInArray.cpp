class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> inlen(n,1);
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                inlen[i+1] = inlen[i+1] + inlen[i];
            }
        }
        vector<int> declen(n,1);
        for(int j=n-2;j>=0;j--){
            if(arr[j]>arr[j+1]){
                declen[j] = declen[j] + declen[j+1];
            }
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(declen[i]!=1 && inlen[i]!=1){
                maxi = max(maxi,inlen[i]+declen[i]-1);
            }
        }
        return maxi<3?0:maxi;
      
    }
};
