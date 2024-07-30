class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int sum=(n*(n+1))/2;
        int add=0;
        for(int i=0;i<n;i++){
            add += nums[i];
            
        }
        return sum-add;
    }
};