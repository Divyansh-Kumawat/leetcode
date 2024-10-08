class Solution {
private:
    vector<int> getZ(string s){
        int n = s.size();
        vector<int> z(n);
        z[0]=0;
        int l=0, r=0;
        for(int i=1; i<n; i++){
            if(i>r){
                l=r=i;
                while(r<n && s[r-l]==s[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
            else{
                int k = i-l;
                if(z[k] < r-i+1){
                    z[i]=z[k];
                }
                else{
                    l=i;
                    while(r<n && s[r-l]==s[r]){
                        r++;
                    }
                    z[i]=r-l;
                    r--;
                }
            }
        }
        return z;
    }
public:
    int strStr(string haystack, string needle) {
        string temp = needle + "$" + haystack;
        int l = temp.size();
        vector<int> z = getZ(temp);

        int n=needle.size();
        for(int i=0; i<l; i++){
            if(z[i]==n){
                return i-n-1;
            }
        }

        return -1;
    }
};