class Solution {
public:
    void firstfunc(const vector<int>& nums, int target, int &first) {
        int n = nums.size();
        int high = n - 1;
        int low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Avoids potential overflow
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;  // Move left to find the first occurrence
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    void lastfunc(const vector<int>& nums, int target, int &last) {
        int n = nums.size();
        int high = n - 1;
        int low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;  // Move right to find the last occurrence
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        firstfunc(nums, target, first);
        lastfunc(nums, target, last);
        return {first, last};
    }
};
