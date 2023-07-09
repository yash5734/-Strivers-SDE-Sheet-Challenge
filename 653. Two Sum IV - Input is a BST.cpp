class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool findTarget(TreeNode* root, int target) {
        map<int, int> mpp;
        vector<int> v;
        inorder(root, v);
        // for (int i = 0; i < v.size(); i++) {
        //     mpp[v[i]] = i;
        // }

        if (v.size() == 1) return false;

        int i= 0;
        int j = v.size()-1;
        while(i!=j){

            int sum = v[i]+v[j];
            if(sum == target) return true;
            if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};
