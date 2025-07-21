class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int count=0;
        for(char ch: s){
            if(stk.empty()){
                stk.push(ch);
                continue;
            }
            if(ch=='('){
                stk.push('(');
            }
            else if(ch==')'){
                if(stk.top()=='('){
                    stk.pop();
                }
                else stk.push(')');
            }

        }
        return stk.size();

    }
};