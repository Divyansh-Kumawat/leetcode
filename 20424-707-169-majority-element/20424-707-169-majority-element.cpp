class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int > mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans=-1;
        for(const auto& element: mpp){
            if(element.second>n/2) {
                ans=element.first;
            }
        }
        return ans;
    }
};