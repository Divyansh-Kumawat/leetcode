class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mpp;
        int n=bills.size();
        for(int i=0;i<n;i++){
            
            mpp[bills[i]]++;
            if(bills[i]==10){
                if(mpp[5]!=0){
                    mpp[5]--;
                }
                else return false;
            }
            else if(bills[i]==20){
                if(mpp[10]!=0 && mpp[5]!=0){
                    mpp[10]--;mpp[5]--;
                }
                else if(mpp[5]>=3){
                    mpp[5]=mpp[5]-3;
                }
                else return false;
            }
            
        }
        return true;
    }
};