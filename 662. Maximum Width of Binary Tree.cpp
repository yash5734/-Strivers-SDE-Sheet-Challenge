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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long ans = 0;
        while(!q.empty()){
            int size = q.size();
            long long currMin = q.front().second;

            long long leftMost = 0, rightMost = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                long long currId = q.front().second - currMin;
                q.pop();

                if(i == 0) leftMost = currId;
                if(i == size - 1) rightMost = currId;

                if(node->left != NULL) q.push({node->left, 2 * currId + 1LL});
                if(node->right != NULL) q.push({node->right, 2 * currId + 2LL});
            }
            ans = max(ans, rightMost - leftMost + 1);
        }
        return ans;
    }
};
