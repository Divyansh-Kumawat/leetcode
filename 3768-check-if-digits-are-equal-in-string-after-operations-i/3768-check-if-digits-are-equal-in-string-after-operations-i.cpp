class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string str="";
            for(int i=0;i<s.size()-1;i++){
                char z=(s[i]-'0'+s[i+1]-'0')%10+'0';
                str+=z;
            }
            s=str;
        }
        if(s[0]==s[1]) return true;
    return false;
    }
    

};