class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int ro = grid.size();
        int co = grid[0].size();
        int vis[ro][co];
        int cnt = 0; // Fresh orange count

        // Initialize vis array and push rotten oranges to the queue
        for (int i = 0; i < ro; i++) {
            for (int j = 0; j < co; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) cnt++;
            }
        }

        int time = 0;
        int countf = 0;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tmax = q.front().second;
            q.pop();

            time = max(time, tmax);

            // Process 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < ro && ncol >= 0 && ncol < co && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, tmax + 1});
                    countf++;
                }
            }
        }

        // If all fresh oranges are not rotten
        if (cnt != countf) return -1;

        return time;
    }
};
