class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        char st[256]={0};
        char ts[256]={0};

        for(int i=0;i<n;i++){
            char a=s[i];
            char b=t[i];
            if((st[a] && st[a]!=b) || ts[b] && ts[b]!=a) return false;

            st[a]=b;
            ts[b]=a;
        }
        return true;
    }
};