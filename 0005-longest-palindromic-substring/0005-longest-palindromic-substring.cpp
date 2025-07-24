class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++){
            int x=i;
            int y=i;
            while(x>=0&& y<n&& s[x]==s[y]){
                
                string pal = s.substr(x, y-x+1 );
                if(pal.size()>str.size()){
                    str=pal;
                }x--;y++;
                
            }
            x=i;
            y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                
                
                string pal = s.substr(x, y-x+1);
                if(pal.size()>str.size()){
                    str=pal;
                }x--;y++;
                
            }
        }
        return str;
    }
};