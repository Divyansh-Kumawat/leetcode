class Solution {
public:
    bool split(vector<int> &nums,int minSum,int k){
        int sum=0; int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>minSum){
                cnt++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            
        }
         return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(split(nums,mid,k)){
                high=mid-1;
            }
            else{
                low=mid+1;

            }
        }
        return low;
    }
};