class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> hash(100,0);
        for(int it:nums){
            if(hash[it]==1){
                ans.push_back(it);
            }else{
                hash[it]=1;
            }
        }
        return ans;
    }
};