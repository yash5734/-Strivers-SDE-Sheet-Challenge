class Solution {
private:
    bool dfs(int node, int vis[], int pathVis[], vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj)) return true;
            } else if (pathVis[it] == 1) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        // for (int i = 0; i < prerequisites.size(); i++) {
        //     int course = prerequisites[i][0];// it takes 1st guy
        //     int prerequisite = prerequisites[i][1];// it takes second guy
        //     adj[course].push_back(prerequisite);
        // }

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        int vis[V];
        int pathVis[V];
        memset(vis, 0, sizeof(vis));
        memset(pathVis, 0, sizeof(pathVis));

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) return false; // If cycle found, return false
            }
        }
        return true;
    }
};
