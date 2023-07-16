class Solution {
private:
    bool check(int node, int vis[], vector<vector<int>>& adj, int color) {
        vis[node] = color;
        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                if (!check(it, vis, adj, 1 - color))
                    return false;
            } else {
                if (vis[it] == color)
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis[n];
        memset(vis, -1, sizeof(vis));

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!check(i, vis, graph, 0))
                    return false;
            }
        }
        return true;
    }
};
