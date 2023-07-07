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
public:

    bool check(TreeNode* a,TreeNode* b){
        if(a==NULL&&b==NULL) return true;
        else if(a==NULL||b==NULL)return false;
        return (a->val == b->val) && check(a->left,b->right) && check(a->right,b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(check(root->left,root->right)){
            return true;
        }
        return false;
    
    }
};
