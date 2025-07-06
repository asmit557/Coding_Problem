void inorder(Node* root, vector<int>&arr){
     if(root==NULL){
         return;
     }
     inorder(root->left,arr);
     arr.push_back(root->data);
     inorder(root->right,arr);
 }

float findMedian(struct Node *root)
{
      //Code here
      vector<int>arr2;
      if(root==NULL){
          return NULL;
      }
      inorder(root,arr2);
      int n=arr2.size();
      if(n%2!=0)
           return arr2[n / 2];
      else 
         return (arr2[(n - 1) / 2] + arr2[n / 2]) / 2.0;
      
}
