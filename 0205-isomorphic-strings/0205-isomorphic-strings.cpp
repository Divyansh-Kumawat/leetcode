class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        map<char,char> mpp;
        for(int i=0;i<s.length();i++){
            char orignal=s[i];
            char replacement=t[i];
            if(!(mpp.find(orignal)!=mpp.end())){
                bool valueexists=false;
                for(auto pair: mpp){
                    if(pair.second==replacement){
                        valueexists=true;
                        break;
                    }
                }
                if(!valueexists){
                    mpp[orignal]=replacement;
                }
                else{
                    return false;
                }
            }else {
            char mappedCharacter = mpp[orignal];
            if (mappedCharacter != replacement) {
                return false;
            }
        }
       
    } return true;
    }
};