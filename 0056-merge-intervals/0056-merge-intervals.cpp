class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());

        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i][1] >= intervals[i+1][0]) {
                // Merge intervals
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                // Erase the merged interval
                intervals.erase(intervals.begin() + i + 1);
            } else {
                i++;
            }
        }
        
        return intervals;
    }
};