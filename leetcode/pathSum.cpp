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
    bool solve(TreeNode* root, int targetSum,int sum){
        if(root==NULL){
            return false;
        }
         sum += root->val;
        if(sum==targetSum && root->right==NULL && root->left==NULL){
            return true;
        }
       
        bool left = solve(root->left,targetSum,sum);
        bool right = solve(root->right,targetSum,sum);

        if(left || right){
            return true;
        }
        else{
            return false;
        }

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = solve(root,targetSum,0);
        return ans;
    }
};
