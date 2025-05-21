class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int cnt=0;
        int maxdepth=0;
        for(char ch:s){
            if(ch=='('){
                cnt++;
            }
            else if(ch==')'){
                cnt--;
            }
            maxdepth=max(maxdepth,cnt);
        }
        return maxdepth;
    }
};