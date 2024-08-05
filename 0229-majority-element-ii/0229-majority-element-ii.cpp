class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        int count=0;
        int x=n/3;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.second>x){
                arr.push_back(it.first);
            }
        }
        return arr;
    }
};