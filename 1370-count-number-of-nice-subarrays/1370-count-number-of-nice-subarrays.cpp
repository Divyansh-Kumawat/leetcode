class Solution {
public:
    int func(vector<int>& nums, int k){
        int freq=0,l=0,r=0,cnt=0;
        int n=nums.size();
        if(k<0) return 0;
        while(r<n){
            if(nums[r]%2==1){
                freq++;
            }
            while(freq>k){
                if (nums[l] % 2 == 1) {
                    freq--;
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};