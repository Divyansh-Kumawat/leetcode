class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // Generate all subset sums for each possible count of elements
        auto getSubsets = [](const vector<int>& arr) {
            int size = arr.size();
            unordered_map<int, vector<int>> subsets; // key = count, value = all sums
            for (int mask = 0; mask < (1 << size); ++mask) {
                int cnt = 0, sum = 0;
                for (int i = 0; i < size; ++i) {
                    if (mask & (1 << i)) {
                        cnt++;
                        sum += arr[i];
                    }
                }
                subsets[cnt].push_back(sum);
            }
            return subsets;
        };

        auto leftMap = getSubsets(left);
        auto rightMap = getSubsets(right);
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int res = INT_MAX;

        // Sort right side for binary search
        for (auto& [cnt, vec] : rightMap) {
            sort(vec.begin(), vec.end());
        }

        for (int k = 0; k <= n; ++k) {
            vector<int>& leftSums = leftMap[k];
            vector<int>& rightSums = rightMap[n - k];

            for (int s1 : leftSums) {
                int target = totalSum / 2 - s1;
                auto& vec = rightSums;
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int s2 = *it;
                    int sumPicked = s1 + s2;
                    int other = totalSum - sumPicked;
                    res = min(res, abs(sumPicked - other));
                }
                if (it != vec.begin()) {
                    --it;
                    int s2 = *it;
                    int sumPicked = s1 + s2;
                    int other = totalSum - sumPicked;
                    res = min(res, abs(sumPicked - other));
                }
            }
        }

        return res;
    }
};
