class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mpp;
        int n=nums.size();
        int max=0;
        
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.second >(nums.size()/2)){
                return it.first;
            }
        }
        return -1;
    }
};