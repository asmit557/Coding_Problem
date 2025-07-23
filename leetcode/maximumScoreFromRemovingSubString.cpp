class Solution {
public:
    string solve(string s,string match){
        stack<char> st;
        for(char ch:s){
            if(ch==match[1] && !st.empty() && st.top()==match[0]){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string result = "";
        while(!st.empty()){
            char ch = st.top();
            result += ch;
            st.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        string maxstr = x > y ? "ab":"ba";
        string minstr = x < y ? "ab":"ba";
        if(x==y){
            maxstr = "ab";
        }
        int score = 0;
        string temp_first = solve(s,maxstr);
        int charremoved = n - temp_first.length();
        score += (charremoved/2) * max(x,y);
        string temp_second = solve(temp_first,minstr);
        charremoved = temp_first.length() - temp_second.length();
        score += (charremoved/2) * min(x,y);
        return score;
    }
};
