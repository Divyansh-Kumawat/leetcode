class Solution {
public:
    int noofdays(vector<int>& weights,int capacity){
        int days=0;
        int cap=0;
        for(int i=0;i<weights.size();i++){
            if(cap+weights[i]<=capacity){
                cap+=weights[i];
            }
            else{
                days++;
                cap=weights[i];
            }
        }
        if(cap>0) days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =  *max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);
        int n=weights.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(noofdays(weights,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

    }
};