class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            reverse(temp.begin(),temp.end());
            if(temp.length()>0)ans+=" "+temp;
        }
        return ans.substr(1);
    }
};