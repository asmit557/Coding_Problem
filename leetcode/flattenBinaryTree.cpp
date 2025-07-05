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
    void solve(TreeNode* &curr){
        while(curr){
         TreeNode* temp = curr;
          if(curr->left){
            temp = temp->left;
            while(temp->right){
                temp = temp->right;
            }
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            curr=curr->right;
        }
        else{
            curr=curr->right;
        }
    }
}
    void flatten(TreeNode* root) {
        solve(root);
    }
};
