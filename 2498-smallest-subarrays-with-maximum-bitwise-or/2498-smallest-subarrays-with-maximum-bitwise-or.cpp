class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> lastseen(32,-1);
        for(int i=n-1;i>=0;i--){
            for(int bits=0;bits<32;bits++){
                if((nums[i]>>bits)&1){
                    lastseen[bits]=i;
                }
            }
            int farthest=i;
            for(int bit=0;bit<32;bit++){
                if(lastseen[bit]!=-1) farthest=max(farthest,lastseen[bit]);
            }
            ans[i]=farthest-i+1;
        }
        return ans;
    }
};