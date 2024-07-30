class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        int count=0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==1){
                count += 1;
                
            }
            else if(nums[i]==0){
                arr.push_back(count);
                count=0;
                
            }
            if(i==n-1){
                arr.push_back(count);
            }
        }
        int x=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>x){
                x=arr[i];
            }
            
        }
        return x;
        
    }
};