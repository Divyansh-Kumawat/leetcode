class Solution {
public:
    void dfs(int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid, int drow[], int dcol[], int row, int col) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfs(n, m, vis, grid, drow, dcol, nrow, ncol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty()) return 0; // Handle edge case of empty grid

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        // Mark all land cells connected to the boundary
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && grid[0][i] == 1) {
                dfs(n, m, vis, grid, drow, dcol, 0, i);
            }
            if (!vis[n-1][i] && grid[n-1][i] == 1) {
                dfs(n, m, vis, grid, drow, dcol, n-1, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(n, m, vis, grid, drow, dcol, i, 0);
            }
            if (!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(n, m, vis, grid, drow, dcol, i, m-1);
            }
        }

        // Count all unvisited land cells
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
