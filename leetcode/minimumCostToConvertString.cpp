class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        int l = s.length();
        int n = cost.size();
        vector<vector<long long>> adj(26,vector<long long>(26,1e11));
        for(int i=0;i<n;i++){
            if((long long)cost[i] < adj[o[i]-'a'][c[i]-'a'])
              adj[o[i]-'a'][c[i]-'a'] = cost[i];
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(i!=j && adj[i][k]!=1e11 && adj[k][j]!=1e11){
                       adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]); 
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<l;i++){
            if(s[i]!=t[i]){
                if(adj[s[i]-'a'][t[i]-'a'] != 1e11){
                    ans += adj[s[i]-'a'][t[i]-'a'];
                }else{
                    return -1;
                }
            }
        }
        return ans;
        
    }
};
