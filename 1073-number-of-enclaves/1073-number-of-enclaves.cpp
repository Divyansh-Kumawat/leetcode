class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>>& vis,int n,int m,int r,int c){
        vis[r][c]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int row=r+drow[i];
            int col=c+dcol[i];
            if(row>=0 && col>=0 && row<n && col<m && vis[row][col]==0 && grid[row][col]==1){
                
                dfs(grid,vis,n,m,row,col);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(grid,vis,n,m,0,i);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1){
                dfs(grid,vis,n,m,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,vis,n,m,i,0);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1){
                dfs(grid,vis,n,m,i,m-1);
            }
        }
         int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};