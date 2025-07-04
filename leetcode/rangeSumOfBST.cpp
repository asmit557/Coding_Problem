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
    // 01 approach - check all node


    // 02 approach - check raange based checking
    int rangeSumBST(TreeNode* root, int &low, int &high) {
        // bc
        if (!root) return 0;

        // out of range
        // skip left subtree
        if (low > root->val) {
            return rangeSumBST(root->right, low, high);
        }
        // skip right subtree
        else if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        // in range
        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
    }
};
