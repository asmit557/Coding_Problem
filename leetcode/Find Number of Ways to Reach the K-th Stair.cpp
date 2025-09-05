class Solution {
public:
   int K;
   unordered_map<string,int> mp;
   int solve(int i,int jumps,int goback){
    if(i > K+1) return 0;
    string str = to_string(i) + to_string(jumps) + to_string(goback);
    if(mp.find(str)!=mp.end())return mp[str];
    int ways = 0;
    if(i==K){
        ways +=1;
    }
    if(goback==1){
        ways += solve(i-1,jumps,0);
    }
    ways += solve(i+pow(2,jumps),jumps+1,1);
    return mp[str] = ways; 
   }
    int waysToReachStair(int k) {
        K =k;
        mp.clear();
        return solve(1,0,1);
    }
};
