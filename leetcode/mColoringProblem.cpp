class Solution {
  public:
    bool possible(int node , vector<vector<int>>&graph,vector<int>&color,int m,int v)
    {
        for(int i = 0 ; i < v ; i++)
        {
            if(graph[node][i] == 1 && color[i] == m)return false;
        }
        return true;
    }
    bool solve(int node , vector<vector<int>>&graph,vector<int>&color,int m,int v)
    {
        if(node == v)
        {
            return true;
        }
        
        for(int i = 1 ; i <= m ; i++)
        {
            if(possible(node,graph,color,i, v))
            {
                color[node] = i;
                if(solve(node+1 , graph , color , m , v) == true)return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edge, int m) {
        // code here
        vector<vector<int>> graph(v, vector<int>(v, 0));
        int k = 0 ;
        int n = edge.size();
        for(int i = 0 ; i < n; i++)
        {
            graph[edge[i][0]][edge[i][1]] = 1;
            graph[edge[i][1]][edge[i][0]] = 1;
        }
        vector<int>color(v , 0);
        return solve(0,graph,color,m,v);
    }
};
