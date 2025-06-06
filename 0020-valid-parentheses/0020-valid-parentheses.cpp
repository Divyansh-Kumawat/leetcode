class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch:s){
            
            if(ch=='{' || ch=='[' || ch=='('){
                stk.push(ch);
            }
            else{
                if(stk.empty()) return false;
            }
            if(ch=='}'){
                if(stk.top()=='{'){
                    stk.pop();
                }
                else{
                    return false;
                }
            }else if(ch==']' ){
                if(stk.top()=='['){
                    stk.pop();
                }
                else{
                    return false;
                }
            }else if(ch==')'){
                if(stk.top()=='('){
                    stk.pop();
                }else{
                    return false;
                }
            }
        
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};