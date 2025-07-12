class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;

        // 1. Push every 0 into the queue (source layer) and mark its distance 0
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }

        const int dx[4] = {1, 0, -1, 0};
        const int dy[4] = {0, 1, 0, -1};

        // 2. Multisource BFS
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;      // bounds
                if (dist[nx][ny] > dist[x][y] + 1) {                        // relax
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
};
