class Solution {
public:
    string reverseWords(string s) {
           stack<char> s1;
      string ans = "";
      for(int i=s.length()-1;i>=0;i--){
          if(s1.empty() && s[i]==' ') continue;
          if(s1.empty() && s[i]!= ' '){
              s1.push(s[i]);
          }
          else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]>='0' && s[i] <='9'){
              s1.push(s[i]);
          }
          else if(s[i]==' '){
               
              while(!s1.empty()){
                  char ch = s1.top();
                  s1.pop();
                  ans.push_back(ch);
                  
              }
              
                ans.push_back(s[i]);
              }
      }
      while(!s1.empty()){
                  char ch = s1.top();
                  s1.pop();
                  ans.push_back(ch);
              }
       string temp = "";       
      for(int i=0;i<ans.length();i++){
          if(i==ans.length()-1 && ans[i]==' ')
            continue;
          temp.push_back(ans[i]);
      }
      return temp;
    }
};
