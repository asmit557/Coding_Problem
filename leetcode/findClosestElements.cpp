class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int index =-1;
        for(int i=0;i<n;i++){
            if(arr[i]>=x){
               index=i;
               break;
            }
        }
        if(index==-1){
            index = n-1;
        }
        vector<pair<int,int>> v;
        int p = index+1;
        while(index>=0){
            int diff = abs(arr[index]-x);
            v.push_back({diff,arr[index]});
            index--;
        }
        while(p<n){
            int diff = abs(arr[p]-x);
            v.push_back({diff,arr[p]});
            p++;
        }
        auto comp = [](const pair<int,int>& p1 , const pair<int,int>& p2){
              if(p1.first!=p2.first) return p1.first< p2.first;
              return p1.second < p2.second;
        };
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++){
           ans.push_back(v[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
