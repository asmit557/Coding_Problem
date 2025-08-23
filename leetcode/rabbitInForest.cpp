class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        sort(answers.begin(),answers.end());
        
        int cnt1 = answers[0] + 1;
        int i = 0;
        int num = answers[0];
        int ans = 0;
        int cnt2 = 0;
        while(i<n){
           if(num==answers[i]){
            cnt2++;
             if(cnt2==cnt1){
                ans += cnt1;
                cnt2=0;
                if(i+1<n){
                  cnt1 = answers[i+1] + 1;
                  num = answers[i+1];
                }else{
                    cnt1 = 0;
                }
             }
           }else{
              num = answers[i];
              cnt2=1;
              ans += cnt1;
              cnt1 = answers[i]+1;
           }
           i++;
        }
        ans += cnt1;
        return ans;
    }
};
