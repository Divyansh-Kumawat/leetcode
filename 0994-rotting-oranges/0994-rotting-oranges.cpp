class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({0,{i,j}});
                }
            }
        }
        int time=0;
        int drow[]={0,0,1,-1};
        int dcol[]={-1,1,0,0};
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int t=q.front().first;
            q.pop();
            time=max(t,time);
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row<n && row>=0 && col<m && col>=0 && grid[row][col]==1 && vis[row][col]==0){
                    vis[row][col]=2;
                    q.push({time+1,{row,col}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return time;

    }
};