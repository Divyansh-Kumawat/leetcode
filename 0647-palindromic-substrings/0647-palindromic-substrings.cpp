class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int x=i;
            int y=i;
            while(x>=0 && y<n && s[x]==s[y]){
                cnt++;
                x--;y++;
            }
            x=i;
            y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                cnt++;
                x--;y++;
                
            }
        }
        return cnt;
    }
};