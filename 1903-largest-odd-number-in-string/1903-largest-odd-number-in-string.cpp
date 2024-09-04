class Solution {
public:
    void reverseString(std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        std::swap(str[left], str[right]); // Swap characters
        ++left;
        --right;
    }
}
    string largestOddNumber(string num) {
        string s="";
        stack<char> stk;
        string character;
        for(char ch:num){
            stk.push(ch);
        }
        while(!stk.empty())
        {
            int x=stk.top();
            if(x%2!=0){
                while(!stk.empty()){
                    s+=stk.top();
                    stk.pop();
                }
                
                
            }
            else{
                stk.pop();
            }
        }
reverseString(s);        
        return s;
        
    }
};