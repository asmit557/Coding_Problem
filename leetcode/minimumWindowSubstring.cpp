class Solution {
public:
static bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& vect) {
        sort(vect.begin(), vect.end(), sortcol);
        int cnt = 0;
        int freetime = vect[0][1];
        for(int i=1;i<vect.size();i++){
            if(vect[i][0] >= freetime){
                freetime = vect[i][1];
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};
