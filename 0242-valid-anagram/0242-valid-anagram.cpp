class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mpps;
        map<char,int> mppt;
        for(char c:s){
            if((mpps.find(c)!=mpps.end())){
                mpps[c]++;
            }
            else{
                mpps[c]=1;
            }
        }
        for(char c:t){
            if((mppt.find(c)!=mppt.end())){
                mppt[c]++;
            }
            else{
                mppt[c]=1;
            }
        }
        int n=mpps.size();
        int m=mppt.size();
        if(n!=m) return false;
        int cnt=0;

        for(const auto& pair: mpps){
            if(mppt.find(pair.first)!=mppt.end()){
                if(pair.second==mppt[pair.first]){
                    cnt++;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(cnt==n)return true;
        return false;
    }
};