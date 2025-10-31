class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mpp;
        for(int it:nums){
            if(mpp.find(it)!=mpp.end()){
                ans.push_back(it);
            }
            else{
                mpp[it]++;
            }
        }
        return ans;
    }
};