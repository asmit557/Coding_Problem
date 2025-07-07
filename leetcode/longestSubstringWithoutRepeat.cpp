class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> m;
       int l = 0;
       int r = 0;
       int maxi = 0;
       while(r<s.length()){
        if(m.find(s[r])==m.end()){
            m[s[r]] = r;
        }
        else{
            if(l<=m[s[r]]){
              l = m[s[r]] + 1;
              m[s[r]] = r;
            }
            else{
                m[s[r]] = r;
            }
        }
        maxi = max(maxi,r-l+1);
        r++;
       }
       return maxi;
    }
};
