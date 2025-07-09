class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int initcolor=image[sr][sc];
        image[sr][sc]=color; 

        q.push({sr,sc});
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        while(!q.empty()){
            int r=q.front().first;
            int c= q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=drow[i]+r;
                int col=dcol[i]+c;
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]!=color && image[row][col]==initcolor){
                    image[row][col]=color;
                    q.push({row,col});
                    vis[row][col]=color;
                }
            }
        }
        return image;
    }
};