class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int mini = INT_MAX;
          string ans ="";
          int n = arr.size();
          for(int i=0;i<n;i++){
            if(arr[i].length() < mini){
                mini = arr[i].length();
                ans = arr[i];
            }
        }
        
        
        
        int index=0;
       while(index<ans.length()){
              char ch = ans[index];
              bool b = false;
           for(int j=0;j<n;j++){
               if(ch!=arr[j][index]){
                   b=true;
                   break;
               } 
           }
           if(b){
               break;
           }
           index++;
       }
       string temp ="";
       for(int i=0;i<index;i++){
           temp += ans[i];
       }
       return temp;
       
    }
};
