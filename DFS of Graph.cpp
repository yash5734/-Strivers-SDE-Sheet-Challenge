class Solution {
  public:
  
    void dfs(int node, vector<int>adj[],vector<int>&vis,vector<int>&arr){
        vis[node]=0;
        arr.push_back(node);
        for(auto &it:adj[node]){
            if(vis[it]==1)
            dfs(it,adj,vis,arr);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>arr;
        vector<int>vis(V,1);
        
        for(int i=0;i<V;i++){
            if(vis[i]==1)
            dfs(i,adj,vis,arr);
        }
        return arr;
    }
};
