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
    TreeNode* f(TreeNode* root, int &k){
        if(root == NULL) return NULL;
        
         TreeNode* left = f(root->left,k);

        if(left != NULL){
            return left;
        }
        k--;
        if(k==0) return root;

        return f(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = f(root,k);
        return ans->val;
    }
};
