class Solution {
  public:
    void insert(Node* &root,int v) {  
        if(root==NULL) {  
            root=newNode(v); 
            return;
        } 
        if(v<root->data)  insert(root->left,v); 
        if(v>root->data)  insert(root->right,v);
    }
    Node* Bst(int pre[], int size) { 
        Node* root=NULL;
      for(int i=0;i<size;i++) {  
          insert(root,pre[i]);
      } 
      return root;
    }
};
