class Solution {
public:
void dfs(int n, int m, vector<vector<int>>& vis, vector<vector<char>>& board, int drow[], int dcol[], int row, int col) {
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol] == 'O'){
                dfs(n,m,vis,board,drow,dcol,nrow,ncol);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        board.size() == 0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && board[0][i] == 'O') {
                dfs(n, m, vis, board, drow, dcol, 0, i);
            }
            if (!vis[n-1][i] && board[n-1][i] == 'O') {
                dfs(n, m, vis, board, drow, dcol, n-1, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(n, m, vis, board, drow, dcol, i, 0);
            }
            if (!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(n, m, vis, board, drow, dcol, i, m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};