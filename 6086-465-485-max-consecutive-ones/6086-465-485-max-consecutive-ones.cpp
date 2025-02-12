class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                sum=sum+1;
                if(i==n-1){
                    maxi=max(sum,maxi);
                }   
                continue;
            }
            else{
                maxi=max(sum,maxi);
                sum=0;
            }
           
        }
        return maxi;
    }
};