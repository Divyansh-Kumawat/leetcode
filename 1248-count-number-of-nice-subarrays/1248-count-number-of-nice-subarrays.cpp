class Solution {
public:
    int func(vector<int>& nums, int goal){
        int r=0,l=0,sum=0,cnt=0;
        if(goal<0) return 0;
        int n=nums.size();
        while(r<n){
            sum=sum+nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
            
            
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;

        }
        return func(nums,k)-func(nums,k-1);

    }
};