class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int longest=1;
        int cntcurr=0;
        int lastSmaller=INT_MIN;
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++){
            if(lastSmaller==nums[i]){
                continue;
            }
            else if(lastSmaller==nums[i]-1){
                cntcurr+=1;
                longest=max(cntcurr,longest);
                lastSmaller=nums[i];
            }
            else{
                lastSmaller=nums[i];
                cntcurr=1;
            }
        }
        return longest;
    }
};