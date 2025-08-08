class Solution {
public:
    pair<int,int> dfs(vector<int> adj[],int node,vector<int> &quiet,vector<int> &answer){
       int mini = quiet.size();
       int person = node;
       if(answer[node]!=-1)return {answer[node],quiet[node]};
       for(auto i:adj[node]){
          pair<int,int> p = dfs(adj,i,quiet,answer);
          if(mini > p.second){
            mini = p.second;
            person = p.first;
          }
       }

       if(quiet[node]<mini){
        mini = quiet[node];
        person = node;
       }
       quiet[node] = mini;
       answer[node] = person;
       return {person,mini};
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        for(auto i:richer){
            int a = i[0];
            int b = i[1];
            adj[b].push_back(a);
        }
         
        vector<int> answer(n,-1);
        for(int i=0;i<n;i++){
           if(answer[i]==-1)
           dfs(adj,i,quiet,answer);
        }
        return answer;
    }
};
