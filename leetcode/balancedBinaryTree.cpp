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
pair<bool,int> solve(TreeNode*root){
           if(root==NULL){
              return make_pair(true,0);
           }
           pair<bool,int> left = solve(root->left);
           pair<bool,int> right = solve(root->right);
           int ans = max(left.second,right.second) + 1;
           bool b = abs(left.second-right.second)<=1;
           if(left.first && right.first && b){
               return make_pair(true,ans);
           }
           else{
               return make_pair(false,ans);
           }
       } 
    bool isBalanced(TreeNode* root) {
         pair<bool,int> ans = solve(root);
         return ans.first;
    }
};
