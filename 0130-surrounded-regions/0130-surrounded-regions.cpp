class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i,int j,int n,int m){
        vis[i][j]=1;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 && c>=0 && r<n && c<m && board[r][c]=='O' && !vis[r][c]){
                dfs(board,vis,r,c,n,m);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,vis,0,i,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                dfs(board,vis,n-1,i,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,vis,i,0,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(board,vis,i,m-1,n,m);
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