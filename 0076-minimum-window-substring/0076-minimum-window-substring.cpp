class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int r=0,l=0,minlen=INT_MAX;
        int stInd=-1,cnt=0,n=s.size();
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        while(r<s.size()){
            if(hash[s[r]]>0) cnt=cnt+1;
            hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    stInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt=cnt-1;
                l++;
            }
            r++;
        }
        return stInd==-1?"": s.substr(stInd,minlen);
    }
};