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
int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right) + 1;
    }
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        pair<int,int> ans;
        ans.second = max(left.second,right.second) + 1;
        ans.first = max(max(left.first,right.first),left.second+right.second + 1);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
         pair<int,int> ans = solve(root);
        return ans.first-1;
    }
};
