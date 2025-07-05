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
 void solve(TreeNode*root,vector<int> &ans,int l){
            if(root==NULL){
                return ;
            }
            if(l==ans.size()){
                ans.push_back(root->val);
            }
            solve(root->right,ans,l+1);
            solve(root->left,ans,l+1);
            
        }
    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;
       int level = 0;
       solve(root,ans,level);
       return ans;
    }
};
