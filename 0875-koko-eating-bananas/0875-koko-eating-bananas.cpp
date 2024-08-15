class Solution {
public:
    long long func(vector<int>& arr,int hour){
        
        long long total=0;
        for(int i=0;i<arr.size();i++){
            total+=ceil((double)arr[i]/(double)hour);
            
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
                maxi=max(maxi,piles[i]);
        }
        int high=maxi;
        int ans=1;
        while(low<=high){
            int mid=(low+high)/2;
            long long totalhrs=func(piles,mid);
            if(totalhrs<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};