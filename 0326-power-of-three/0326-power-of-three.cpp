class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=0;
        while(pow(3,i)<=n){
            if(pow(3,i)==abs(n)) return true;
            i++;
        }
        return false;
    }
};