class Solution {
  public:
    int count =0;
    int getCount(Node *root, int l, int h) {
                
                if (root==NULL) return 0;
                  if (root->data<=h && root->data>=l) count++;
                 getCount(root->left , l ,h);           
                 getCount(root->right , l ,h);           
                
                return count;
                
        
    }
};
