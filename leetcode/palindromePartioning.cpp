class Solution {
public:
    bool isPalindrome(int start,int end,string s){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> &path,int index,string s){
        if(index==s.length()){
            cout<<1<<" ";
            ans.push_back(path);
            return ;
        }

        for(int i = index;i<s.length();++i){
            if(isPalindrome(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                solve(ans,path,i+1,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(ans,path,0,s);
        return ans;
    }
};
