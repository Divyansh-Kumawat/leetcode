class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0;
        int r = nums.length-1;
        if (target<nums[l]) return 0;
        if (target>nums[r]) return nums.length;
        while (l<r) {
            int val = l+(r-l)/2;
            if (nums[val] == target) return val;
            if (nums[val] < target) l = val+1;
            else r = val;
        }    
        return l;
    }
}