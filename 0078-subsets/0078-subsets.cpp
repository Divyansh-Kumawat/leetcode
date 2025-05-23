class Solution {
public:
    void generate(vector<int>&nums , vector<vector<int>>& ans,int i,vector<int>& temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        generate(nums,ans,i+1,temp);
        temp.pop_back();
        generate(nums,ans,i+1,temp);

        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(nums,ans,0,temp);
        return ans;

        
    }
};