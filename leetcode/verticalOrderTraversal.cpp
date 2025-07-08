
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,vector<pair<int,int>>> mp;
        queue<tuple<TreeNode*,int,int>> q;
        q.push({root,0,0});
        while(!q.empty()){
            auto [node,row,col] = q.front();
            q.pop();
            mp[col].push_back({row,node->val});
            if(node->left) q.push({node->left,row+1,col-1});
            if(node->right) q.push({node->right,row+1,col+1});
        }

        for(auto [k,v]:mp){
            sort(v.begin(),v.end());
            vector<int> tmp;
            for(auto [i,j]:v){
                tmp.push_back(j);
            }
            res.push_back(tmp);
            
        }

        
        return res;
    }
};
