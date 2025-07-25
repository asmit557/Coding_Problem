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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       queue<TreeNode*> q;
       q.push(root);
       if(root==NULL){
        return ans;
       }
       while(!q.empty()){
          vector<int> v;
          int size = q.size();
          for(int i=0;i<size;i++){
             TreeNode* top = q.front();
             q.pop();
             v.push_back(top->val);
             if(top->left){
                q.push(top->left);
             }
             if(top->right){
                q.push(top->right);
             }
          }
          ans.push_back(v);
       }
       return ans;
    }
};
