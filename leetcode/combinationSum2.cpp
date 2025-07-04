class Solution {
public:
    vector<vector<int>>v;
    void combination(vector<int>&candidates,int sum,vector<int>&v1,int target,int index){
        int n=candidates.size();
         if(target==sum){
            v.push_back(v1);
            return;
        }
        if (index == n || sum>target) { //we have reached here  this means target!=sum or index==n
            return;
        }
        for(int i=index;i<n;i++){  //i ---index check 
            if(sum+candidates[i]>target){ //if totalsum>target then break
                break;
            }
            if(i>index&&candidates[i]==candidates[i-1]){//duplicate
                continue;
            }
            else{
                v1.push_back(candidates[i]);//inplace
                combination(candidates,sum+candidates[i],v1,target,i+1);//recursive call
                v1.pop_back();//backtrack removal
            }
        }
       

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>v1;
        combination(candidates,0,v1,target,0);
        return v;

    }
};
