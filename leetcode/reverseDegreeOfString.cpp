class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int> m;
        char ch = 'a';
        for(int i=26;i>=1;i--){
            m[ch] = i;
            ch++;
        }
        
        int sum = 0;
        for(int i=0;i<s.length();i++){
            sum += m[s[i]]*(i+1);
        }
        return sum;
    }
};
