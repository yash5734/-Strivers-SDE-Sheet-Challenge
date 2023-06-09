class Solution
{
    private:
    Node* f(Node* root, int &k){
        if(root == NULL){
            return NULL;
        }
        
        Node * right = f(root->right,k);
        
        if(right!=NULL){
            return right;
        }
        k--;
        if(k==0) return root;
        return f(root->left,k);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        Node* ans = f(root,K);
        return ans->data;
    }
};
