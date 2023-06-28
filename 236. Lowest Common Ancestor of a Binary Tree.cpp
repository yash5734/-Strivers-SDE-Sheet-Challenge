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
    private:
    bool solve(TreeNode* root, TreeNode* target, vector<TreeNode*>&ds){
        if(root == NULL) return false;

        ds.push_back(root);
        if(root == target) return true;

        if(solve(root->left,target,ds)|| solve(root->right,target,ds)) return true;

        ds.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        vector<TreeNode*>vec1;
        vector<TreeNode*>vec2;
        solve(root,p,vec1);
        solve(root,q,vec2);

        int itr1 =0,itr2 =0;
        TreeNode* ans;
        while(itr1<vec1.size() && itr2<vec2.size()){
            if(vec1[itr1]==vec2[itr2]){
                ans = vec1[itr1];
            }
            itr1++;
            itr2++;
        }
        return ans;
    }
};
