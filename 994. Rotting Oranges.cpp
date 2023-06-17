class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt =0;
        int temp =0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    vis[i][j] =1;
                    q.push({0,{i,j}});
                }
                else{
                    vis[i][j] =0;
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int ans =0;

        while(!q.empty()){
            int step = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            ans = max(ans,step);

            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr<n&&nr>=0&&nc<m&&nc>=0&&vis[nr][nc]==0&&grid[nr][nc]==1){
                    q.push({step+1,{nr,nc}});
                    vis[nr][nc] =2;
                    temp++;
                }
            }
        }

        if(temp!=cnt) return -1;
        return ans;

    }
};
