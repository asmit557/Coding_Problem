class Solution {
public:
vector<int> result;
int n;
int target;
unordered_map<string,int> dp;
    void solve( vector<int> skillset,int i,vector<int> &temp,int mask){
        if(i>=skillset.size()){
            if(target==mask){
                if(result.size()==0 || result.size()>temp.size()){
                    result = temp;
                }
            }
            return ;
        }

        if(result.size()!=0 && result.size()<temp.size())return;
        string str = to_string(i) + " " + to_string(mask);
        if(dp.find(str)!=dp.end()){
            if(dp[str] <= temp.size()){
                return ;
            }
        } 
        solve(skillset,i+1,temp,mask);
        if((mask | skillset[i])!=mask){
            temp.push_back(i);
            solve(skillset,i+1,temp,mask| skillset[i]);
            temp.pop_back();
             dp[str] = temp.size()==0 ? -1:temp.size();
        } 
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        unordered_map<string,int> stringtoindex;
        
        for(int i=0;i<n;i++){
            stringtoindex[req_skills[i]] = i;
        }
        vector<int> skillset;
        for(auto v:people){
            int i=0;
            for(auto str:v){
                i = i | (1 << stringtoindex[str]);
            }
            skillset.push_back(i);
        }
        vector<int> temp;
        target = pow(2,n)-1;
        solve(skillset,0,temp,0);
        return result;
    }
};
