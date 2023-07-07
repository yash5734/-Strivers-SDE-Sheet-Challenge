/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* temp) {
        if(temp==NULL) return NULL;
        Node* root = temp;
        set<Node*>st;
        queue<pair<Node*,int>>q;
        map<int,Node*>mp;
        q.push({root,0});

        while(!q.empty()){
            Node* node = q.front().first;
            int step = q.front().second;
            q.pop();

            node->next = NULL;

            if(mp.find(step) != mp.end()){
                node->next = mp[step];
                mp[step] = node;
            }else{
                mp[step] = node;
            }

            if(node->right != NULL) q.push({node->right,step+1});
            if(node->left != NULL) q.push({node->left,step+1});
        }
        return temp;
    }
};
