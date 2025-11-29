class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int area=0;
        int i=0;
        int j=n-1;
        while(i<j){
            int len=j-i;
            int hig=min(height[j],height[i]);
            area=max(area,len*hig);
            if(height[i]<height[j]){
                i++;
            }
            else j--;
        }
        return area;

    }
};