class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, pair<int, int>>> pq; 
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        if(grid[0][0]==0){
            dist[0][0]=1;
            pq.push({1,{0,0}});
        }   
        else return -1;
        int drow[]={0,1,0,-1,-1,1,1,-1};
        int dcol[]={1,0,-1,0,-1,1,-1,1};
        while(!pq.empty()){
            int dis=pq.front().first;
            int r=pq.front().second.first;
            int c=pq.front().second.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(col>=0 && row>=0 && row<n && col<m){
                    if(grid[row][col]==0 && dist[row][col]>dis+1){
                        dist[row][col]=dis+1;
                        pq.push({dis + 1, {row, col}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==1e9) return -1;
        return dist[n-1][m-1];
    }
};