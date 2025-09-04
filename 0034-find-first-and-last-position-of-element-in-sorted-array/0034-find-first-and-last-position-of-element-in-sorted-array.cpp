class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                int x=mid;
                int y=mid;
                while(x>0&& nums[x-1]==target){
                    x--;
                }
                while(y<n-1 &&nums[y+1]==target){
                    y++;
                }
                ans[0]=x;
                ans[1]=y;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;

            }
        }
        return ans;
    }
};