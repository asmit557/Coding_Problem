/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        if(root->val >= p->val && root->val <= q->val){
            return root;
        }
        else if(root->val <= p->val && root->val >= q->val){
            return root;
        }
        else if(p->val > root->val && q->val > root->val){
            return  solve(root->right,p,q);
        }
        else if(p->val < root->val && q->val < root->val){
            return solve(root->left,p,q);
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = solve(root,p,q);
        return ans;
    }
};
