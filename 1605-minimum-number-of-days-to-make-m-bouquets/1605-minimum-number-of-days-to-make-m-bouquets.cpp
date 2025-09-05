class Solution {
public:
    int ispossible(vector<int>& bloomDay,int n,int k,int mid){
        int cnt=0;
        int booket=0;
        for(int i=0;i<n;i++){
            if (bloomDay[i] <= mid) {
            cnt++;
                if (cnt == k) {   // ✅ make bouquet immediately
                    booket++;
                    cnt = 0;
                }
            } else {
                cnt = 0; // reset streak if flower hasn't bloomed
            }
        }
        return booket;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(bloomDay,n,k,mid)>=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};