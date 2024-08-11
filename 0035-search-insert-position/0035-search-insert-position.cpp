class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int x=0;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;                         
            }
            else if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            
            
            
        }
        if(target>nums[n-1]){
            return n;
        }
        if(target<nums[0]){
            return 0;
        }
        return ans;
        
    }
};