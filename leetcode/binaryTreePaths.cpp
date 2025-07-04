/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<string> &ans,string path){
         if(root==NULL){
            cout<<1<<" ";
            return ;
         }
         if(root->right==NULL && root->left==NULL){
            path += to_string(root->val);
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        
        path += to_string(root->val);
        path += "->";
        solve(root->left,ans,path);
        solve(root->right,ans,path);
        path.pop_back();
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        solve(root,ans,path);
        return ans;
    }
};
