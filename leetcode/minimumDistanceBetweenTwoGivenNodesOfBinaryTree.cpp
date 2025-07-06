class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int LCA(Node* root, int a, int b, int& ans){
        if(root == nullptr){
            return -1;
        }
        int leftDist = LCA(root->left, a, b, ans);
        int rightDist = LCA(root->right, a, b, ans);
        if(leftDist != -1 && rightDist != -1){
            ans = leftDist + rightDist + 2; 
            return -1;
        }
        else if(leftDist != -1 || rightDist != -1){
            if(root->data == a || root->data == b){
                ans = 1 + max(leftDist, rightDist);
                return -1;
            }
            else{
                return 1 + max(leftDist, rightDist);
            }
        }
        else{
            if(root->data == a || root->data == b){
                return 0;
            }
        }
        return -1;
    }
    int findDist(Node* root, int a, int b) {
        int ans = -1;
        LCA(root, a, b, ans);
        return ans;
        // Your code here
        
    }
};
