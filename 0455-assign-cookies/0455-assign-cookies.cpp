class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gsize=g.size();
        int ssize=s.size();
        map<int,int> mpp;
        for(int it:s){
             mpp[it]++;
        }
        int cnt=0;
        for(int i=0;i<gsize;i++){
            for(auto it=mpp.begin();it!=mpp.end();it++){
                if(it->first>=g[i] && it->second>0){
                    cnt++;
                    it->second--;
                    break;
                }
            }
           
        }
        return cnt;
    }
};