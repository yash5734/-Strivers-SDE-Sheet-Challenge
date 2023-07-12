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
    private:
    TreeNode* f(vector<int>& inorder, int inStart, int inEnd, vector<int>& preorder, int preStart, int preEnd, map<int,int>&mp){

        if(inStart>inEnd||preStart>preEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int elem = mp[root->val];
        int nelem = elem-inStart;

        root->left = f(inorder,inStart,elem-1,preorder,preStart+1,preStart+nelem,mp);
        root->right = f(inorder,elem+1,inEnd,preorder,preStart+nelem+1,preEnd,mp);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inStart =0,inEnd = inorder.size()-1;
        int preStart = 0, preEnd = preorder.size()-1;

        map<int,int>mp;
        for(int i=0;i<=inEnd;i++){
            mp[inorder[i]] = i;
        }
        return f(inorder,inStart,inEnd,preorder,preStart,preEnd,mp);
    }
};
