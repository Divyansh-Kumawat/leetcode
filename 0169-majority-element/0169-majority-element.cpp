class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majele=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                majele=nums[i];
                cnt=1;
            }
            else if(nums[i]==majele){
                cnt++;
            }
            else{
                cnt--;
            }

           
        }
        int total=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majele) total++;
        }
        return (total > n / 2) ? majele : -1;
    }
};