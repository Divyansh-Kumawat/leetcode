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
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int time=0;
        int count=0;
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int t=q.front().first;
            q.pop();
            time=max(time,t);
            for(int i=0;i<4;i++){
                int row=drow[i]+r;
                int col=dcol[i]+c;
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && vis[row][col]==0)
                {
                    vis[row][col]=2;
                    q.push({t+1,{row,col}});
                    count++;
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};