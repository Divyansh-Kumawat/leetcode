class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int maxi=0;
        map<char,int> mpp;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                if(l<mpp[s[r]]+1){
                    l=mpp[s[r]]+1;

                }  
            }
            int len=r-l+1;
                maxi=max(maxi,len);
            mpp[s[r]]=r;
            r++;

        }
        return maxi;
    }
};