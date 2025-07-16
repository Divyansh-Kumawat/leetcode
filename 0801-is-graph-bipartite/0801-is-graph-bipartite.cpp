class Solution {
    bool dfs(const vector<vector<int>>& graph,
             int node,
             vector<int>& color,
             int flag)             // no need to pass n
    {
        color[node] = flag;

        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                if (!dfs(graph, nei, color, !flag))   // propagate failure
                    return false;
            } else if (color[nei] == flag) {
                return false;                         // same colour on both ends
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {                     // new component
                if (!dfs(graph, i, color, 0))
                    return false;
            }
        }
        return true;
    }
};
