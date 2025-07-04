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
  bool solve(struct TreeNode*r1,struct TreeNode*r2){
          if(r1==NULL && r2!=NULL){
              return false;
          }
          if(r1!=NULL && r2==NULL){
              return false;
          }
          if(r1==NULL && r2==NULL){
              return true;
          }
          bool pt1 = solve(r1->left,r2->right);
          bool pt2 = solve(r1->right,r2->left);
          bool cond = r1->val==r2->val;
          if(pt1 && pt2 && cond){
              return true;
          }
          else{
              return false;
          }
      }
    bool isSymmetric(TreeNode* root) {
         if(root==NULL){
            return true;
        }
	   bool b = solve(root->left,root->right);
	   return b;
    }
};
