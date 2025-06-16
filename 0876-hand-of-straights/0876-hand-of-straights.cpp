class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        int n=hand.size();
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            int start=it->first;
            int freq=it->second;
            if(freq>0){
                     for(int i=0;i<groupSize;i++){
                        if(mpp[i+start]<freq){
                            return false;
                        }
                        mpp[start + i] -= freq;
            }
            
                }
           
        }
        return true;
    }
};