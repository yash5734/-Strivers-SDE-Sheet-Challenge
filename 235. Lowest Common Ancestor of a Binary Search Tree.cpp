/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    bool rootToNode(TreeNode* root, TreeNode* p,vector<TreeNode*>&v){
        if(root == NULL) return false;
        v.push_back(root);
        if(root == p) return true;
        if(rootToNode(root->left,p,v)) return true;
        if(rootToNode(root->right,p,v)) return true;

        v.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;

        vector<TreeNode*>v1;
        vector<TreeNode*>v2;

        rootToNode(root,p,v1);
        rootToNode(root,q,v2);
        int it1 =0,it2 =0;
        TreeNode* c;
        while(it1<v1.size()&&it2<v2.size()){
            if(v1[it1] == v2[it2]){
                c = v1[it1];
            }
            it1++;
            it2++;
        }
        return c;
    }
};
