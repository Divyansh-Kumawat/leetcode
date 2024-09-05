class Solution {
public:
    int maxDepth(string s) {
        int currentOpen=0;
        int maxOpen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                currentOpen++;
                
            }
            else if(s[i]==')'){
                currentOpen--;
            }
            maxOpen=max(maxOpen,currentOpen);
        }
        return maxOpen;
    }
};