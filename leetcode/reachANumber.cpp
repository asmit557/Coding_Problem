class Solution {
public:
    
    int reachNumber(int target) {
        target=abs(target);
        int mini=INT_MAX;
        for(int i=1;;i++){
            long long sum=1LL*i*(i+1)/2;
            if(abs(sum-target)%2)continue;
            if(sum<target)continue;
            mini=i;
            break;
        }
        return mini;
    }
};
