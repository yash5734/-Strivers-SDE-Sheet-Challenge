vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    vector<int>inorder;
    vector<int>preorder;
    vector<int>postorder;

    stack<pair<BinaryTreeNode<int>*,int>>st;

    st.push({root,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        BinaryTreeNode<int>* node = it.first;
        int num = it.second;

        if(num==1){
            preorder.push_back(node->data);
            num++;
            st.push({node,num});

            if(node->left != NULL) st.push({node->left,1});
        } 

        else if(num == 2){
            inorder.push_back(node->data);
            num++;
            st.push({node,num});

            if(node->right!=NULL) st.push({node->right,1});
        }

        else if(num ==3){
            postorder.push_back(node->data);
        }
    }
    
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;

}
