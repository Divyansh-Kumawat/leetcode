class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxi=INT_MIN;
        for(char ch:s){
            if(ch=='('){
                cnt++;
            }
            else if(ch==')') cnt--;
            maxi=max(cnt,maxi);
        }
        return maxi;
        
    }

};