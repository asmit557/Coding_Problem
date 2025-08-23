/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
   void dfs(unordered_map<int,vector<int>> &adj,int id,int &ans,unordered_map<int,int> &mp){
       ans += mp[id];
       for(auto i:adj[id]){
          dfs(adj,i,ans,mp);
       }
   }
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            Employee* e = employees[i];
            mp[e->id] = e->importance;
            vector<int> v = e->subordinates;
            for(int j=0;j<v.size();j++){
                adj[e->id].push_back(v[j]);
            }
           
        } 
        int ans = 0;
        dfs(adj,id,ans,mp);
        return ans;
    }
};
