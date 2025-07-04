class Solution {
public:
    Node* small = nullptr, *large = nullptr;
    
    // Function to find the largest value smaller than the key (Predecessor)
    void findSmall(Node* root, int key){
        if(root == nullptr) return;
        
        if(root->data < key){
            small = root; // Update predecessor
            findSmall(root->right, key); // Look for a larger predecessor
        }else{
            // If current node's data >= key, move left
            findSmall(root->left, key);
        }
    }

    // Function to find the smallest value larger than the key (Successor)
    void findLarge(Node* root, int key){
        if(root == nullptr) return;
        
        if(root->data > key){
            large = root; // Update successor
            findLarge(root->left, key); // Look for a smaller successor
        }else{
            // If current node's data <= key, move right
            findLarge(root->right, key);
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        findSmall(root, key); // Find predecessor
        findLarge(root, key); // Find successor
        
        return {small, large}; // Return both as a vector
    }
};
