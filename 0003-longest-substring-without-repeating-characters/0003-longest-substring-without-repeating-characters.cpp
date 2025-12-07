class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int lmax=0;
        int n=s.size();
        vector<int> mpp(256,-1);
        while(r<n){
            if(mpp[s[r]]!=-1){
                if(l<=mpp[s[r]]+1){
                    l=mpp[s[r]]+1;
                }
            }
            int len=r-l+1;
            lmax=max(len,lmax);
            mpp[s[r]]=r;

            r++;
        }
        return lmax;
        
    }
};