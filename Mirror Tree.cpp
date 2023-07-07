class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(root == NULL) return ;
        Node* temp = root->left;
        Node* temp2 = root->right;
        root->left = temp2;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
        
    }
};
