class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                arr.push_back(nums[i]);
                j++;
                
            }
        }
        while(j<n){
            arr.push_back(0);
            j++;
        }
        for(int i=0;i<n;i++){
            nums[i]=arr[i];
        }
    }
};