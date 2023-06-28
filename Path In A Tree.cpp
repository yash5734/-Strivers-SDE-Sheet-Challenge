#include <bits/stdc++.h> 
using namespace std;
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool f(TreeNode<int> *root, int target, vector<int> &ds){
	if(root == NULL) return false;
	
	ds.push_back(root->data);

	if(root->data == target){
		return true;
	}
	
	if(f(root->left, target, ds)||f(root->right,target,ds)) return true;
	ds.pop_back();
	return false;

}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ds;
	if(root == NULL) return ds;
	vector<int> ans;
	if(f(root,x,ds))
	return ds;
	return {};
	
}
