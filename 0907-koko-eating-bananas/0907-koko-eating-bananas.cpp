class Solution {
public:
    long long func(vector<int>& piles,int h,int mid){
        long long hours=0;
        int i=0;
        while(i<piles.size()){
            hours+=ceil((double)piles[i]/(double)mid);
            i++;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(func(piles,h,mid)<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};