class Solution
{
    private:
    void f(Node* root, vector<Node*>&inorder){
        if(root==NULL) return;
        
        f(root->left,inorder);
        inorder.push_back(root);
        f(root->right,inorder);
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        vector<Node*>inorder;
        f(root,inorder);
        pre = NULL;
        suc = NULL;
        
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]->key<key){
                pre = inorder[i];
            }else if(inorder[i]->key>key){
                suc = inorder[i];
                break;
            }
            
        }
    }
};
