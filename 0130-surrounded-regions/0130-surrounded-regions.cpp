class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m,int r,int c){
        vis[r][c]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int col=c+dcol[i];
            int row=r+drow[i];
            if(row>=0 && col>=0 && row<n && col<m && board[row][col]=='O' && vis[row][col]==0){
                dfs(board,vis,n,m,row,col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,vis,n,m,0,i);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                dfs(board,vis,n,m,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,vis,n,m,i,0);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(board,vis,n,m,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
    }
};