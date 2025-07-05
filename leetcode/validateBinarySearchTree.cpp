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
    bool solve(TreeNode* root,long long maxi, long long mini){
        if(root==NULL){
            return true;
        }
        if(root->val <= mini || root->val >= maxi){
            return false;
        }

        bool left = solve(root->left,root->val,mini);
        bool right = solve(root->right,maxi,root->val);

        if(left && right){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root->right==NULL && root->left==NULL){
            return true;
        }
       return solve(root,LLONG_MAX,LLONG_MIN);
    }
};
