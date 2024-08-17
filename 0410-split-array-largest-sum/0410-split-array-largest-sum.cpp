class Solution {
public:
    int fun(vector<int>& nums, int max_sum){
        int n=1;
        int asum=0;
        for(int i=0;i<nums.size();i++){
            if(asum+nums[i]<=max_sum){
                asum+=nums[i];
                
            }
            else{
                n++;
                asum=nums[i];
            }
        }
        return n;
    }
        
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()){
            return -1;
        }
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(nums[i],maxi);
            
        }
        if(k==nums.size()){
            return maxi;
        }
        int low= maxi;
        int high=sum;
        while(low<=high){
            int mid=(low +high)/2;
            int nos=fun(nums,mid);
            if(nos>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }         
        }
        return low;
    }
};