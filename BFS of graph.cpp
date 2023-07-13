class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        q.push(0);
        vector<int>ans;
        vector<int>vis(V,1);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it:adj[node]){
                if(vis[it]==1){
                    vis[it] =0;
                    q.push(it);
                }
            }
            ans.push_back(node);
        }
        return ans;
    }
};
