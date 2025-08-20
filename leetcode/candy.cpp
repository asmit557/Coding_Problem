class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
       vector<int> left(N);
        left[0] = 1;
        
        for(int i=1;i<N;i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            else left[i] = 1;
        }
        int curr;
        int right = 1;
        int sum = max(left[N-1],1);
        for(int i=N-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                curr = right +1;
                right = curr;
                
            }
            else{
                curr = 1;
                right = curr;
            }
            sum += max(curr,left[i]);
            
        }
        return sum; 
    }
};
