#include<math.h>
class Solution {
public:
    bool isPowerOfTwo(int n) {
         for(int i =0;i<31;i++){
             int power=pow(2,i);
             if(n==power){
                 return true;
             }
         }
        return false; 
    }
};
