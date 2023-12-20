class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length-1;
        int x=1;
        for (int i=1;i<=n;i++){
            if(nums[i]!=nums[i-1]){
                nums[x]=nums[i];
                x++;
            }
            else{
                continue;
            }

        }
     
        return x;

    }
}