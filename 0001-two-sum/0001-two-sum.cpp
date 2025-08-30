class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mpp;
        int sum=0;
        mpp[nums[0]]=0;
        vector<int> ans;
        for(int i=1;i<n;i++){
            int rem=target-nums[i];
            if(mpp.find(rem)!=mpp.end()){
                ans.push_back(mpp[rem]);
                ans.push_back(i);
                break;
            }
            mpp[nums[i]]=i;

        }
        return ans;
    }
};