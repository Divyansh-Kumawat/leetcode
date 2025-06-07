class Solution {
public:
    int trap(vector<int>& height) {
           int n=height.size();if (n == 0) return 0;
        vector<int> prefmax(n), sufmax(n);
        int total=0;
     
        prefmax[0]=height[0];
        for(int i=1;i<n;i++){
            prefmax[i]=max(prefmax[i-1],height[i]);
        }
        sufmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufmax[i] = max(sufmax[i + 1], height[i]);
        }
        for(int i=0;i<n;i++){
            // if(height[i]<sufmax[i] && height[i]< prefmax[i]){
                total+=min(sufmax[i],prefmax[i])-height[i];
            // }
        }
        return total;
    }
};