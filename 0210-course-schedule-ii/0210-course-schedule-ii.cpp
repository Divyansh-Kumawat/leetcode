class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        vector<int> indegree(numCourses, 0);

        // Calculate indegree of each node
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Push nodes with 0 indegree to the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // Check if all courses can be completed
        if (topo.size() == numCourses) {
            return topo;
        }
        return {};  // Return an empty vector if a cycle is detected
    }
};
