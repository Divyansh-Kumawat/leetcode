
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& [task, count] : freq) {
            maxHeap.push(count);
        }

        int time = 0;

        while (!maxHeap.empty()) {
            int cycle = n + 1;
            vector<int> temp;
            int tasksThisCycle = 0;

            // Try to execute up to cycle tasks
            for (int i = 0; i < cycle && !maxHeap.empty(); i++) {
                int curr = maxHeap.top(); maxHeap.pop();
                if (--curr > 0) {
                    temp.push_back(curr);
                }
                time++;
                tasksThisCycle++;
            }

            // Push remaining back to heap
            for (int cnt : temp) {
                maxHeap.push(cnt);
            }

            // If heap is not empty, add idle time
            if (!maxHeap.empty()) {
                time += (cycle - tasksThisCycle);
            }
        }

        return time;

    }
};