class Solution {
public:
    int reverse(int x) {
        long y=0;
        int z=x;
        while(z!=0){
            int a=z%10;
            y= 10*y+a;
             z=z/10;
        }
        if(y>INT_MAX || y<INT_MIN) return 0; // check range if r is outside the range then              return 0  ;
        return long(y);
        
    }
};