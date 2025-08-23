class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin() , words.end());
        unordered_set<string> map;
        string res;
        for(int i = 0, n = words.size(); i < n; ++i){
            int len = words[i].length();
            if(len == 1 || map.count(words[i].substr(0 , len - 1))){
                if(len > res.length()) res = words[i];
                map.insert(words[i]);
            }
        }
        return res;
    }
};
