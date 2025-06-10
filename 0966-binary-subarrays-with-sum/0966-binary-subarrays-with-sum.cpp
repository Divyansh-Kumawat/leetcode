class Solution {
public:
    int func(vector<int>& nums, int goal
    ){
        int n=nums.size(),l=0,r=0,sum=0,cnt=0;
        if(goal<0) return 0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;   
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         return func(nums,goal)-func(nums,goal-1);
        
    }
};