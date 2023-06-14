class Solution{
    public:
    
    void solve(int i, int j, vector<vector<int>> vis, string str, vector<string> &ans,vector<vector<int>>m, int n, int *di,int *dj){
        
    // base case
    if(i==n-1 && j==n-1){
        ans.push_back(str);
        return;
    }
    
    // recursive statement
    string a = "DLRU";
    for(int ind = 0;ind<4;ind++){
        int nexti = i+di[ind];
        int nextj = j+dj[ind];
        
        if(nexti>=0&&nexti<n&&nextj>=0&&nextj<n && vis[nexti][nextj]==0 && m[nexti][nextj]==1){
            vis[i][j] = 1;
            solve(nexti,nextj,vis,str+a[ind],ans,m,n,di,dj);
            vis[i][j] = 0;
        }
    }
}    
    vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<vector<int>> vis(n,vector<int> (n,0));
       vector<string> ans;
       int di[] = {1,0,0,-1};
       int dj[] = {0,-1,1,0};
       
       
       if(m[0][0]) solve(0,0,vis,"",ans,m,n,di,dj);
       return ans;
    }
};
