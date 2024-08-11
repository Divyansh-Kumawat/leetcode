class Solution {
public:

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;        
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return idx;
//     int func(vector<int>& nums,vector<int>& arr,int low,int high,int target){
//         if(low>high){
//             return;
//         }
        
//     }
    // vector<int> searchRange(vector<int>& nums, int target) {
        // int n=nums.size();
        // vector<int> arr;
        // int low = 0;
        // int high=n-1;
        // func(nums,arr,low,high,target);
        
        
//         int count=0;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(nums[mid]==target){
//                 arr.push_back(mid);
//                 int count1 =mid+1;
//                 int count2 =mid-1;
//                 // while(nums[count2]==target ){
//                 //     arr.push_back(count2);
//                 //     count--;
//                 // }
//                 return arr;
//             }
//             else if(nums[mid]>target){
//                 high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         if(arr.empty()){
//             arr.push_back(-1);
//             arr.push_back(-1);

//         }
//         return arr;
    }
};