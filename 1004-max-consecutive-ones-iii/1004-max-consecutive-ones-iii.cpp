class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0;
        int l=0;
        int cnt=0;
        int maxi=0,len=0;
        while(r<nums.size()){
            if(nums[r]==0){
                cnt++;
            }
            if(cnt>k){
                if(cnt>k){
                    if(nums[l]==0){
                        cnt--;
                    }l++;
                }
            }
            if(cnt<=k){
                len=r-l+1;
                maxi=max(len,maxi);
            }
            r++;
        }
        return maxi;
    }
};