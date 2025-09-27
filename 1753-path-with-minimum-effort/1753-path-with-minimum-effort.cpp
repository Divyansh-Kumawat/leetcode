class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int drow[]={0,1,-1,0};
        int dcol[]={1,0,0,-1};
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
            if (r == n - 1 && c == m - 1) return d;

            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && col>=0 && row<n && col<m){
                    int diff=abs(heights[r][c]-heights[row][col]);
                    int maxeffort=max(d,diff);
                    if(dist[row][col]>maxeffort){
                        dist[row][col]=maxeffort;
                        pq.push({maxeffort,{row,col}});
                    }

                }
            }
        }
        return 0;
    }
};