class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int lmax=0;
        int maxfreq=0;
        vector<int> hash(26,0);
        while(r<n){
            hash[s[r]-'A']++;
            int len=r-l+1;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            
            if(len-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxfreq<=k){
                lmax=max(lmax,r-l+1);
            }
            
            r++;
            
        }
        return lmax;
    }
};