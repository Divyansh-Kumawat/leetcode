class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};

        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int currdist=q.front().first;
            q.pop();
            ans[row][col]=currdist;
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && c>=0 && r<n && c<m && !vis[r][c]){
                    vis[r][c]=1;
                    q.push({currdist+1,{r,c}});
                }

            }


        }
        return ans;
        
    }
};