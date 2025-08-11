class Solution {
public:
    bool check(vector<int>& houses,vector<int>& heaters,int mid){
        int i=0,j=0;
        while(i<houses.size() && j<heaters.size()){
             if(houses[i]>=heaters[j]-mid && houses[i]<=heaters[j]+mid){
                      i++;
             }else{
                j++;
             }
        }
        if(i==houses.size())return true;
        else return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int left = 0;
        int right = 1e9;
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        int ans = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(check(houses,heaters,mid)){
                cout<<mid<<endl;
                 ans = mid;
                 right = mid - 1;
            }else{
                 left = mid + 1;
            }
        }

        return ans;
    }
};
