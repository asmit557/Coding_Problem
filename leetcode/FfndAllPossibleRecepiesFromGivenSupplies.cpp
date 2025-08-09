class Solution {
public:
    map<string, vector<string>> adj;
    map<string, bool> visited;
    set<string> avail;
    map<string, bool> memo;

    bool dfs(string curr){
        cout<<curr<<endl;
        if(avail.count(curr)) return true;
        // if(visited[curr]) return true;
        if(memo.count(curr)) return memo[curr];

        if(adj.find(curr) == adj.end()) return false;
        memo[curr] = false;
        for(auto &i : adj[curr]){
            if(!dfs(i)) return false;
        }

        avail.insert(curr);
        return memo[curr] = true;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        for(int i=0; i<n; i++){
            for(string &j: ingredients[i]){
                adj[recipes[i]].push_back(j);
            }
        }

        // for(auto &str: supplies){
        //     visited[str] = true;
        // }

        for(auto &str : supplies){
            avail.insert(str);
        }

        vector<string> res;
        for(auto &st : recipes){
            if(dfs(st)){
                res.push_back(st);
            }
        }
        return res;
    }
};
