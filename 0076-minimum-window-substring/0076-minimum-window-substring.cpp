class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        for(char ch:t){
            hash[ch]++;
        }
        int n=s.size();
        int m=t.size();
        int r=0, l=0, minlen=INT_MAX, cnt=0, stInd=-1;
        while(r<n){
            if(hash[s[r]]>0){
                cnt++;
                
            }
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    stInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return (stInd==-1)?"":s.substr(stInd,minlen);
    }
};