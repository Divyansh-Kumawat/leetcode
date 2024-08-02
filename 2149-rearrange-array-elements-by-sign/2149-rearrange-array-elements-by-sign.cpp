class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,0);
        int e=0;
        int o=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                arr[e]=nums[i];
                e=e+2;
            } 
            else{
                arr[o]=nums[i];
                o=o+2;
            }
        }
       
        
        return arr;
    }
};