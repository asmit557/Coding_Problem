class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st;
        int n = arr.size();
      for(int i = 0;i<n;i++){
          st.insert(arr[i]);
      }
      int maxi = -1;
      for(auto i:st){
          if(st.find(i-1)!=st.end()){
              continue;
          }
          
          int cnt = 1;
          int temp = i;
          while(st.find(temp+1)!=st.end()){
              cnt++;
              temp++;
          }
          maxi = max(maxi,cnt);
          
      }
      if(maxi==-1) return 0;
      return maxi;
    }
};
