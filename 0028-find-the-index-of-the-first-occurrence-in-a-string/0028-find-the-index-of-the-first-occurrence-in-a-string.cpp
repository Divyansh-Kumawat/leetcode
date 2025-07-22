class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int h=haystack.size();
        if (n == 0) return 0;

        for(int i=0;i<=h-n;i++){
            int j=i;
            int k=0;
            while(k<n && haystack[j]==needle[k]){
                k++;
                j++;
            }
            if(k==n) return i;

        }
        return -1;
    }
};