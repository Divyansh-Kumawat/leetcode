class Solution {
public:
    void func(vector<int> nums,vector<vector<int>> &ans,vector<int> temp,int i,int n){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(nums,ans,temp,i+1,n);
        temp.pop_back();
        func(nums,ans,temp,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0,n=nums.size();
        func(nums,ans,temp,i,n);
        return ans;
    }
};