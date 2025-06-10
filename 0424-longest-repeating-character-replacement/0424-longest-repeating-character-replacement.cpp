class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int maxfq=0;
        int maxlen=0;
        vector<int> hash(26,0);
        while(r<n){
            
                hash[s[r]-'A']++;
                maxfq=max(maxfq,hash[s[r]-'A']);
                if((r-l+1)-maxfq>k){
                    hash[s[l]-'A']--;
                    l++;
                }
            
            if((r-l+1)-maxfq<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
            
        }
        return maxlen;
        
    }
};