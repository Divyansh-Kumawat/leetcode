class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }
        
        long y=0;
        int z=x;
        while(z!=0){
            int a=z%10;
            y= 10*y+a;
             z=z/10;
        }
        if(y==x){
            return true;
            
        }
        else{return false;}
        
    }
};