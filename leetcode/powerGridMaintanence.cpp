class Solution {
public:
    vector<int> p,r;
    vector<set<int>> os;
    vector<bool> on;

    int find(int i){
        if(p[i]!=i){
            p[i]=find(p[i]);
        }
        return p[i];
    }

    void merge(int i,int j){
        int p_u = find(i);
        int p_v = find(j);
        if(p_u==p_v)return ;


        if(r[p_u]<r[p_v]){
            p[p_u]=p_v;
            os[p_v].insert(os[p_u].begin(),os[p_u].end());
            os[p_u].clear();
        }else{
            p[p_v] = p_u;
            os[p_u].insert(os[p_v].begin(),os[p_v].end());
            os[p_v].clear();
            if(r[p_u]==r[p_v])r[p_u]++;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        p.resize(c+1);
        r.assign(c+1,0);
        os.resize(c+1);
        on.assign(c+1,true);

        int i=1;
        while(i<=c){
            p[i]=i;
            os[i].insert(i);
            i++;
        }


        for(auto &i:connections){
            merge(i[0],i[1]);
        }


        vector<int> ans;

        for(auto &query:queries){
            int t_ype = query[0];
            int i = query[1];

            if(t_ype==1){
                if(on[i]){
                    ans.push_back(i);
                }else{
                    int p_x = find(i);
                    if(os[p_x].empty()){
                        ans.push_back(-1);
                    }else{
                        ans.push_back(*os[p_x].begin());
                    }
                }
            }else if(t_ype==2){
                if(!on[i])continue;
                on[i]=false;
                int p_x=find(i);
                os[p_x].erase(i);
            }
        }

        return ans;
        
    }
};
