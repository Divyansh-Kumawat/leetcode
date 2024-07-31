class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> arr;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++)
            if(nums[i]+nums[j]==target){
                arr.push_back(i);
                arr.push_back(j);
               
            }
        }
        return  arr ;
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         int left=0;
//         int right=n-1;
//         vector<int> arr;
//         while(left<right){
//             int sum=nums[left]+nums[right];
//             if(sum==target){
//                 arr.push_back(left);
//                 arr.push_back(right);
//             }
//             else if(sum<target){
//                 left++;
//             }
//             else{
//                 right--;
//             }
//         }
        
//         return arr;
    }
};