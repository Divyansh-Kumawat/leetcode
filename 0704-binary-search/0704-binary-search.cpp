class Solution {
public:
    int func(vector<int>& nums,int low,int high,int target){
        if(low>high){
            return -1;
        }
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
            
        }
        else if(nums[mid]<target){
            return func(nums,mid+1,high,target);
        }
        return func(nums,low,mid-1,target);

    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        return func(nums,low,high,target);
        
    }
};