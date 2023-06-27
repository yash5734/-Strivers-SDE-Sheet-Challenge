vector<int> leftView(Node *root)
{
   // Your code here
   queue<pair<Node*, int>>q;
   vector<int>ans;
   if(root==NULL)return ans;
   map<int,int>mp;
   q.push({root,0});
   while(!q.empty()){
       Node* node = q.front().first;
       int line = q.front().second;
       q.pop();
       
       if(mp.find(line)==mp.end()){
           mp[line] = node->data;
       }
       
       if(node->left!=NULL) q.push({node->left,line+1});
       if(node->right!=NULL) q.push({node->right,line+1});
       
   }
   
   for(auto it:mp){
       ans.push_back(it.second);
   }
   return ans;
}
