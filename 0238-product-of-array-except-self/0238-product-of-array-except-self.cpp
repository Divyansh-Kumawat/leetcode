class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        vector<int> ans(n,0);
        bool flag=0;
        bool flag2=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                prod*=nums[i];
                flag2=1;
            }
            else{
                flag=1;
                cnt++;
            }
            
        }
        if(!flag2 || cnt>1) return ans;
        for(int i=0;i<n;i++){
            if(flag){
                if(nums[i]!=0){
                    ans[i]=0;
                }
                else{
                    ans[i]=prod;
                }
                
            }
            else{
                ans[i]=(prod/nums[i]);
            }
        }
        return ans;
    }
};