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
    int solve(TreeNode* root,unordered_map<int,int> &m){
        if(root==NULL){
            return 0;
        }
        int left = solve(root->left,m);
        int right = solve(root->right,m);
        int sum = 0;
         sum += root->val + left + right;
         m[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> m;
       int ans =  solve(root,m);
        int maxi = 0 ;
        for(auto i: m){
            if(i.second > maxi){
                maxi = i.second;
            }
        }
        vector<int> v;
        for(auto i: m){
            if(maxi==i.second){
                v.push_back(i.first);
            }
        }
        return v;
    }
};
