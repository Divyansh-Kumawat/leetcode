class Solution {
public:
    bool canarrange(vector<int> nums,int k,int maxsum){
        int sum=0;
        int cnt=1;
        if(nums.size()==k) return -1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=maxsum){
                sum+=nums[i];
            }
            else{
                cnt++;;
                sum=nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(canarrange(nums,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};