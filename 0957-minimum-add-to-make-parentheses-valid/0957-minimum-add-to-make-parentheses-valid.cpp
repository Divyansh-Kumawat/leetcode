class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int open=0;
        int close=0;
        for(char ch: s){
            
            if(ch=='('){
                open++;
            }
            else if(ch==')'){
                if(open>0){
                    open--;
                }
                else{
                    close++;
                }
            }

        }
        return open+close;

    }
};