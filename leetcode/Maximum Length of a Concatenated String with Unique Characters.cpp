class Solution {
public:
    bool isDuplicate(string temp,string str){
         vector<int> alpha(26,0);
         for(int i=0;i<str.length();i++){
             alpha[str[i]-'a']++;
             if(alpha[str[i]-'a']>1)return true;
         }
         for(int i=0;i<temp.length();i++){
             if(alpha[temp[i]-'a']>0)return true;
         }
         return false;
    }
    int solve(vector<string> &arr,string temp,int index){
       if(index>=arr.size()){
        return 0;
       }
       
       string pass = temp;
       int take = 0;
       if(!isDuplicate(temp,arr[index])){
          temp += arr[index];
          take = arr[index].length() + solve(arr,temp,index+1);
       }
       int nottake = solve(arr,pass,index+1);
       return max(take,nottake);

    }
    int maxLength(vector<string>& arr) {
        return solve(arr,"",0);
    }
};
